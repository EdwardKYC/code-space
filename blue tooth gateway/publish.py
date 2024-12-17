import paho.mqtt.client as mqtt
import keyboard  # 偵測鍵盤輸入

# 建立 MQTT Client
client = mqtt.Client()

# 連接到 MQTT Broker
broker_address = "test.mosquitto.org"  # 若是雲端請填入雲端的 Broker 地址
client.connect(broker_address, 1883)

# MQTT 主題
topic = "city/control"

# 定義按鍵回調函數
def on_key_press(event):
    if event.name == "up":
        message = "Move Up"
        client.publish(topic, message)
        print(f"已發布: {message}")
    elif event.name == "down":
        message = "Move Down"
        client.publish(topic, message)
        print(f"已發布: {message}")
    elif event.name == "left":
        message = "Move Left"
        client.publish(topic, message)
        print(f"已發布: {message}")
    elif event.name == "right":
        message = "Move Right"
        client.publish(topic, message)
        print(f"已發布: {message}")
    elif event.name == "q":  # 按下 'q' 鍵退出程式
        print("程序結束！")
        client.disconnect()
        exit()

# 設定監聽按鍵
keyboard.on_press(on_key_press)

print("按上下左右鍵來傳遞訊息，按 'q' 鍵退出程式")

# 保持程式運行
keyboard.wait("q")  # 等待 'q' 鍵按下來結束程式
