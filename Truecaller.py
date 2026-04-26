import requests
import phonenumbers
from phonenumbers import carrier, geocoder
import json
import time
import random

class SimplePhoneLookup:
    def __init__(self):
        self.ABSTRACT_API_KEY = "4930bc47514446c78d55a7c0047ddc6d"  # Replace with your own key if needed
        
        # Headers to mimic real browser requests
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
            'Accept': 'application/json, text/plain, */*',
            'Accept-Language': 'en-US,en;q=0.9',
            'Accept-Encoding': 'gzip, deflate, br',
            'Connection': 'keep-alive',
            'Upgrade-Insecure-Requests': '1',
        }

    def lookup_name_truecaller_style(self, phone_number):
        """
        Try to find the name associated with a phone number using various methods
        """
        # Method 1: Try NumLookup API (Free service)
        name = self.lookup_name_numlookup(phone_number)
        if name:
            return name
            
        # Method 2: Try TrueCaller-like lookup (experimental)
        name = self.lookup_name_experimental(phone_number)
        if name:
            return name
            
        # Method 3: Try social media/public directory search
        name = self.lookup_name_social(phone_number)
        if name:
            return name
            
        return "Unknown"

    def lookup_name_numlookup(self, phone_number):
        """
        Use NumLookup API for name lookup
        """
        try:
            # Clean phone number
            clean_number = phone_number.replace('+', '').replace(' ', '').replace('-', '')
            
            url = f"https://www.numlookup.com/api/validate/{clean_number}"
            response = requests.get(url, headers=self.headers, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                if data.get('name'):
                    return data['name']
        except Exception as e:
            print(f"NumLookup API error: {e}")
        return None

    def lookup_name_experimental(self, phone_number):
        """
        Experimental method to find names using public directories
        """
        try:
            # Clean phone number
            clean_number = phone_number.replace('+', '').replace(' ', '').replace('-', '')
            
            # Try different public lookup services
            apis = [
                f"https://api.whocalld.com/get_caller_name?phone={clean_number}",
                f"https://calleridservice.com/api/lookup?number={clean_number}",
            ]
            
            for api_url in apis:
                try:
                    response = requests.get(api_url, headers=self.headers, timeout=8)
                    if response.status_code == 200:
                        data = response.json()
                        # Check for various name fields
                        name_fields = ['name', 'caller_name', 'display_name', 'owner_name']
                        for field in name_fields:
                            if data.get(field):
                                return data[field]
                except:
                    continue
                    
            # Add small delay to avoid being blocked
            time.sleep(random.uniform(1, 3))
            
        except Exception as e:
            print(f"Experimental lookup error: {e}")
        return None

    def lookup_name_social(self, phone_number):
        """
        Try to find name through social media and public directories
        """
        try:
            # Clean phone number
            clean_number = phone_number.replace('+', '').replace(' ', '').replace('-', '')
            
            # Try WhitePages-style lookup
            url = f"https://www.whitepages.com/phone/{clean_number}"
            response = requests.get(url, headers=self.headers, timeout=10)
            
            if response.status_code == 200:
                # Basic HTML parsing to find name patterns
                content = response.text.lower()
                
                # Look for common name patterns in HTML
                import re
                name_patterns = [
                    r'<title>([^<]+) \(\d+\)',
                    r'"name":"([^"]+)"',
                    r'<h1[^>]*>([^<]+)</h1>',
                    r'data-name="([^"]+)"'
                ]
                
                for pattern in name_patterns:
                    match = re.search(pattern, content)
                    if match:
                        name = match.group(1).strip()
                        if name and len(name) > 1 and not name.lower().startswith('phone'):
                            return name.title()
                            
        except Exception as e:
            print(f"Social lookup error: {e}")
        return None

    def lookup_with_abstract(self, phone_number):
        try:
            url = "https://phonevalidation.abstractapi.com/v1/"
            params = {
                'api_key': self.ABSTRACT_API_KEY,
                'phone': phone_number
            }
            response = requests.get(url, params=params, timeout=10)
            data = response.json()
            if data.get('valid'):
                country_info = data.get('country', {})
                return {
                    'phone': data.get('phone'),
                    'country': country_info.get('name', 'Unknown'),
                    'location': data.get('location', 'Unknown'),
                    'carrier': data.get('carrier', 'Unknown'),
                }
            else:
                return None
        except Exception:
            return None

    def lookup_with_phonenumbers(self, phone_number):
        try:
            parsed = phonenumbers.parse(phone_number, None)
            if phonenumbers.is_valid_number(parsed):
                carrier_name = carrier.name_for_number(parsed, "en")
                location = geocoder.description_for_number(parsed, "en")
                return {
                    'phone': phonenumbers.format_number(parsed, phonenumbers.PhoneNumberFormat.E164),
                    'country': location.split(',')[-1].strip() if location else 'Unknown',
                    'location': location or 'Unknown',
                    'carrier': carrier_name or 'Unknown',
                }
            else:
                return None
        except Exception:
            return None

    def lookup_phone(self, phone_number):
        print("Searching for phone number information...")
        
        # Get basic phone info
        apis = [
            self.lookup_with_abstract,
            self.lookup_with_phonenumbers
        ]
        
        result = None
        for api_func in apis:
            result = api_func(phone_number)
            if result:
                break
        
        if not result:
            result = {
                'phone': phone_number,
                'country': 'Unknown',
                'location': 'Unknown',
                'carrier': 'Unknown',
            }
        
        # Add name lookup
        print("Searching for owner name ...")
        owner_name = self.lookup_name_truecaller_style(phone_number)
        result['owner_name'] = owner_name
        
        # Add spam/scam check
        print("Checking for spam/scam reports...")
        spam_info = self.check_spam_reports(phone_number)
        result['spam_info'] = spam_info
        
        return result

    def check_spam_reports(self, phone_number):
        """
        Check if the number is reported as spam/scam
        """
        try:
            clean_number = phone_number.replace('+', '').replace(' ', '').replace('-', '')
            
            # Check multiple spam databases
            spam_apis = [
                f"https://www.shouldianswer.com/phone-number/{clean_number}",
                f"https://www.truecaller.com/search/in/{clean_number}",
            ]
            
            for api_url in spam_apis:
                try:
                    response = requests.get(api_url, headers=self.headers, timeout=5)
                    if response.status_code == 200:
                        content = response.text.lower()
                        
                        # Check for spam indicators
                        spam_indicators = ['spam', 'scam', 'fraud', 'telemarketer', 'robocall']
                        for indicator in spam_indicators:
                            if indicator in content:
                                return f"WARNING: Potentially {indicator.title()}"
                except:
                    continue
                    
            return "CLEAN: No spam reports found"
            
        except Exception:
            return "UNKNOWN: Could not check spam status"

def main():
    print("\n\nPhone Number Lookup")
    print("=" * 60)
    print("Features:")
    print("  - Phone number validation")
    print("  - Carrier & location lookup")
    print("  - Owner name identification ")
    print("  - Spam/scam detection")
    print("=" * 60)
    
    phone_number = input("Enter phone number (with country code): ").strip()
    
    if not phone_number:
        print("ERROR: Please enter a valid phone number")
        return
    
    lookup = SimplePhoneLookup()
    result = lookup.lookup_phone(phone_number)
    
    print("\n" + "=" * 60)
    print("LOOKUP RESULTS")
    print("=" * 60)
    print(f"Phone: {result['phone']}")
    print(f"Owner Name: {result.get('owner_name', 'Unknown')}")
    print(f"Country: {result['country']}")
    print(f"Location: {result['location']}")
    print(f"Carrier: {result['carrier']}")
    print(f"Spam Status: {result.get('spam_info', 'Unknown')}")
    print("=" * 60)
    
    # Additional info if name is found
    if result.get('owner_name') and result.get('owner_name') != 'Unknown':
        print(f"SUCCESS: Name found - {result['owner_name']}")
        print("NOTE: Name lookup results may vary in accuracy")
    else:
        print("INFO: Owner name not found in public databases")
        print("TIP: The number might be private or unlisted")

if __name__ == "__main__":
    main()