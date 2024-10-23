from flask import Flask, request, jsonify, render_template
import json
import os

app = Flask(__name__)
DATA_FILE = os.path.join("data", "sensor_data.json")

#dashboard
@app.route('/')
def index():
    # Read sensors
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, 'r') as f:
            data = json.load(f)
    else:
        data = {"temperature": "N/A", "humidity": "N/A"}
    
    return render_template('index.html', data=data)

#Receive
@app.route('/update_data', methods=['POST'])
def update_data():
    data = request.json
    if data:
        with open(DATA_FILE, 'w') as f:
            json.dump(data, f)
        return jsonify({"status": "success", "data": data}), 200
    else:
        return jsonify({"status": "error"}), 400

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
