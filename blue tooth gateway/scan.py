# -*- coding: utf-8 -*-
import asyncio
from bleak import BleakScanner
import paho.mqtt.client as mqtt
import requests
from datetime import datetime
import json

# MQTT 配置
mqtt_broker = "172.22.105.97"  # 我的 MQTT Broker 地址
mqtt_port = 1883
mqtt_topic = "bluetooth/data"

# API Gateway 配置
API_URL = "https://<your-api-gateway-id>.execute-api.<region>.amazonaws.com/<stage>"  # 替換為你的 API Gateway URL

# 初始化 MQTT 客戶端
client = mqtt.Client()
client.connect(mqtt_broker, mqtt_port, 60)

# 發布數據到 MQTT
def publish_to_mqtt(name, address, rssi):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    payload = {
        "name": name if name else "Unknown",  # 如果名稱為空，填入 "Unknown"
        "address": address,
        "rssi": rssi,
        "timestamp": timestamp
    }
    json_payload = json.dumps(payload)
    client.publish(mqtt_topic, json_payload)
    print(f"[MQTT] Published: {json_payload}")

# 發送數據到 API Gateway
def send_to_api(name, address, rssi):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    payload = {
        "name": name if name else "Unknown",  # 如果名稱為空，填入 "Unknown"
        "address": address,
        "rssi": rssi,
        "timestamp": timestamp
    }
    try:
        response = requests.post(API_URL, json=payload)
        print(f"[API] Sent: {payload}")
        print(f"[API] Response: {response.status_code}, {response.text}")
    except Exception as e:
        print(f"[API] Error: {e}")

# 掃描藍牙裝置並傳遞數據
async def scan_devices():
    while True:
        print("開始掃描藍牙裝置...")
        devices = await BleakScanner.discover()
        for device in devices:
            name = device.name  # 獲取裝置名稱
            print(f"發現裝置: {name if name else 'Unknown'} ({device.address}), RSSI: {device.rssi} dB")
            # 發送數據到 MQTT 和 API
            publish_to_mqtt(name, device.address, device.rssi)
            send_to_api(name, device.address, device.rssi)
        print("掃描結束，等待 10 秒...")
        await asyncio.sleep(10)  # 每 10 秒掃描一次

# 主程式入口
if __name__ == "__main__":
    try:
        asyncio.run(scan_devices())
    except KeyboardInterrupt:
        print("程序終止。")

'''
class DeviceModel:
    def __init__(self):
        self.devices = []

    def add_device(self, mac_address, name):
        self.devices.append({"mac_address": mac_address, "name": name})

    def get_devices(self):
        return self.devices
'''
'''
from flask import Flask, jsonify, request
from models import DeviceModel

app = Flask(__name__)
device_model = DeviceModel()

@app.route("/add_device", methods=["POST"])
def add_device():
    data = request.json
    mac_address = data["mac_address"]
    name = data["name"]
    device_model.add_device(mac_address, name)
    return jsonify({"status": "success", "devices": device_model.get_devices()})

@app.route("/get_devices", methods=["GET"])
def get_devices():
    return jsonify(device_model.get_devices())

'''
