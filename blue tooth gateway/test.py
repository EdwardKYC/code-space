import paho.mqtt.client as mqtt

mqtt_broker = "172.27.68.52"
mqtt_port = 1883
mqtt_topic = "test/topic"
mqtt_client = mqtt.Client()

def connect_mqtt():
    try:
        print("Connecting to MQTT broker...")
        mqtt_client.connect(mqtt_broker, mqtt_port, 60)
        mqtt_client.loop_start()
    except Exception as e:
        print(f"Connection failed: {e}")

def publish_message(message):
    try:
        print(f"Publishing message: {message}")
        mqtt_client.publish(mqtt_topic, message)
    except Exception as e:
        print(f"Publish error: {e}")

connect_mqtt()
publish_message("This is a test message from Raspberry Pi")
