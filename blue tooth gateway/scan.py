# -*- coding: utf-8 -*-

import asyncio
import time
from bleak import BleakScanner
import paho.mqtt.client as mqtt
from datetime import datetime

# MQTT 設置
mqtt_broker = "172.22.105.97"
mqtt_port = 1883
mqtt_topic = "bluetooth/data"

# 初始化 MQTT 客戶端
client = mqtt.Client()
client.connect(mqtt_broker, mqtt_port, 60)

# 發布數據到 MQTT
def publish_data(address, rssi):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    payload = {"address": address, "rssi": rssi, "timestamp": timestamp}
    client.publish(mqtt_topic, str(payload))
    print(f"Published data: {payload}")

# 掃描並發送數據
async def scan_devices():
    while True:
        print("開始掃描裝置...")
        devices = await BleakScanner.discover()
        for device in devices:
            print(f"發現裝置 {device.address}, RSSI={device.rssi} dB")
            publish_data(device.address, device.rssi)
        print("掃描結束，等待 10 秒...")
        await asyncio.sleep(10)  # 每 10 秒掃描一次

# 執行掃描
asyncio.run(scan_devices())