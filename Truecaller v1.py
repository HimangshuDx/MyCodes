import requests
import phonenumbers
from phonenumbers import carrier, geocoder

class SimplePhoneLookup:
    def __init__(self):
        self.ABSTRACT_API_KEY = "4930bc47514446c78d55a7c0047ddc6d"  # Replace with your own key if needed

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
        apis = [
            self.lookup_with_abstract,
            self.lookup_with_phonenumbers
        ]
        for api_func in apis:
            result = api_func(phone_number)
            if result:
                return result
        return {
            'phone': phone_number,
            'country': 'Unknown',
            'location': 'Unknown',
            'carrier': 'Unknown',
        }

def main():
    print("Phone Number Lookup (Carrier, Country, Location)")
    print("=" * 50)
    phone_number = input("Enter phone number (with country code, e.g. +911234567890): ").strip()
    lookup = SimplePhoneLookup()
    result = lookup.lookup_phone(phone_number)
    print("\nResult:")
    print(f"Phone: {result['phone']}")
    print(f"Country: {result['country']}")
    print(f"Location: {result['location']}")
    print(f"Carrier: {result['carrier']}")

if __name__ == "__main__":
    main() 