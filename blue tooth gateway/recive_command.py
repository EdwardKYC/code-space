import paho.mqtt.client as mqtt
import json
import time

BROKER_ADDRESS = "test.mosquitto.org"
"
PORT = 1883
DEVICE = "rasp1"
TOPIC = DEVICE + "/commands"

COMMAND_CATEGORIES = {
    "cancel_rasp_navigation": "raspberry_pi_navigation",
    "cancel_device_navigation": "device_navigation",
    "add_rasp_direction": "raspberry_pi_direction",
    "add_device_color": "device_color"
}

# 當接收到訊息時的回調函數
def on_message(client, userdata, message):
    try:
        payload = json.loads(message.payload.decode("utf-8"))
        action = payload.get("action")

        if action in COMMAND_CATEGORIES:
            category = COMMAND_CATEGORIES[action]
            handle_command(category, payload)
        else:
            print(f"[Warning] 未知的指令: {action}")
    except json.JSONDecodeError:
        print("[Error] 無法解析收到的 JSON 資料")

def handle_command(category, payload):
    """ 根據指令類別進行處理 """
    if category == "raspberry_pi_navigation":
        print(f"處理 Raspberry Pi 導航取消指令: {payload}")

    elif category == "device_navigation":
        user_name = payload.get("userName")
        print(f"取消 {user_name} 的導航指令")

    elif category == "raspberry_pi_direction":
        direction = payload.get("direction")
        user_name = payload.get("userName")
        print(f"為 {user_name} 新增 Raspberry Pi 導航方向指令: {direction}")

    elif category == "device_color":
        device_id = payload.get("deviceId")
        color = payload.get("color")
        print(f"為裝置 {device_id} 新增顏色: {color}")

# 設置 MQTT 客戶端
client = mqtt.Client()
client.on_message = on_message

def on_disconnect(client, userdata, rc):
    print(f"[Warning] 與 MQTT Broker 的連線斷開，等待 60 秒後嘗試重新連線...")
    try:
        client.reconnect()
        print("[Info] 重新連線成功")
    except Exception as e:
        print(f"[Error] 無法重新連線: {e}")

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("[Info] 成功連線到 MQTT Broker")
        client.subscribe(TOPIC)
    else:
        print(f"[Error] 連線失敗，返回碼: {rc}")

client.on_disconnect = on_disconnect
client.on_connect = on_connect

try:
    client.connect(BROKER_ADDRESS, PORT, 60)
except Exception as e:
    print(f"[Error] 初次連線失敗: {e}")
    on_disconnect(client, None, None)

print("[Info] 開始接收來自雲端的指令...")
client.loop_forever()
