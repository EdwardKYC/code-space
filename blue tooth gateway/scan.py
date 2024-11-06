# -*- coding: utf-8 -*-

import asyncio
import time
from bleak import BleakScanner
import paho.mqtt.client as mqtt
from datetime import datetime

# MQTT �]�m
mqtt_broker = "172.22.105.97"
mqtt_port = 1883
mqtt_topic = "bluetooth/data"

# ��l�� MQTT �Ȥ��
client = mqtt.Client()
client.connect(mqtt_broker, mqtt_port, 60)

# �o���ƾڨ� MQTT
def publish_data(address, rssi):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    payload = {"address": address, "rssi": rssi, "timestamp": timestamp}
    client.publish(mqtt_topic, str(payload))
    print(f"Published data: {payload}")

# ���y�õo�e�ƾ�
async def scan_devices():
    while True:
        print("�}�l���y�˸m...")
        devices = await BleakScanner.discover()
        for device in devices:
            print(f"�o�{�˸m {device.address}, RSSI={device.rssi} dB")
            publish_data(device.address, device.rssi)
        print("���y�����A���� 10 ��...")
        await asyncio.sleep(10)  # �C 10 ���y�@��

# ���汽�y
asyncio.run(scan_devices())