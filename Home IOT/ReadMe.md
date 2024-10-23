# Smart Home Dashboard with IoT Integration

This project demonstrates a simple IoT-based smart home system where real-time sensor data from temperature and humidity collected by using an Arduino, sent to a Flask server, and displayed on a web-based dashboard.

## Features
- Real-time temperature and humidity monitoring.
- Web-based dashboard to visualize the data.
- Arduino integration with DHT11 sensor and ESP8266 module.

### Arduino
1. Connect the DHT11 sensor to your Arduino/ESP8266.
2. Update the `main.ino` with your WiFi credentials and server IP.
3. Upload the code to your Arduino.

### Flask Server
1. Install Python dependencies:
   ```bash
   pip install flask
