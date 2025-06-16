# Import the required library
import QRcode

# Create a QR code containing the desired text
qr_img = QRcode.make("Hello, This is Himangshu")

# Save the generated QR code as an image file
qr_img.save("qr-img.jpg")