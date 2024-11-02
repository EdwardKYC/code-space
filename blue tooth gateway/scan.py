from bluepy import btle
import time
import paho.mqtt.client as mqtt
from datetime import datetime

mqtt_broker = "172.22.105.97"  # 我的MQTT伺服器地址
mqtt_port = 1883
mqtt_topic = "bluetooth/data"

client = mqtt.Client()
client.connect(mqtt_broker, mqtt_port, 60)

class ScanDelegate(btle.DefaultDelegate):
    def __init__(self):
        btle.DefaultDelegate.__init__(self)

    def handleDiscovery(self, dev, isNewDev, isNewData):
        if isNewDev:
            print(f"Discovered device {dev.addr}, RSSI={dev.rssi} dB")
            publish_data(dev.addr, dev.rssi)

def publish_data(address, rssi):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    payload = {"address": address, "rssi": rssi, "timestamp": timestamp}
    client.publish(mqtt_topic, str(payload))
    print(f"Published data: {payload}")

def scan_devices():
    scanner = btle.Scanner().withDelegate(ScanDelegate())
    devices = scanner.scan(10.0)  # 掃描10秒

while True:
    scan_devices()
    time.sleep(10)  # 每隔10秒掃描一次
