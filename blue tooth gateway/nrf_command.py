from bleak import BleakClient
import asyncio

BT_UUID_CUSTOM_SERVICE = "0c71e180-65d9-4c88-82be-6d33b1c1b9be"
BT_UUID_CUSTOM_CHAR = "eadf8a4a-659d-4c88-82be-6d33b1c1b9be"

async def send_message_to_ble_device(client, message):
    """
    傳送訊息到已連線的 BLE 裝置。

    :param client: 已連線的 BleakClient 對象
    :param message: 要傳送的訊息
    :param characteristic_uuid: 可寫入的 Characteristic UUID
    """
    try:
        print("開始傳送訊息...")
        encoded_message = message.encode('utf-8')
        await client.write_gatt_char(BT_UUID_CUSTOM_CHAR, encoded_message)
        print(f"訊息已發送: {message}")
    except Exception as e:
        print(f"發送訊息時發生錯誤: {e}")
