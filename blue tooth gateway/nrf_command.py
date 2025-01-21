from bleak import BleakClient
import asyncio

BT_UUID_CUSTOM_SERVICE = "0c71e180-65d9-4c88-82be-6d33b1c1b9be"
BT_UUID_CUSTOM_CHAR = "eadf8a4a-659d-4c88-82be-6d33b1c1b9be"

def get_user_input():
    """
    從終端機讀取用戶輸入。
    """
    try:
        return input("輸入要傳送的訊息（輸入 'exit' 結束）：")
    except EOFError:
        return "exit"

async def send_message_to_ble_device(device_address, characteristic_uuid):
    """
    連線到 BLE 裝置，持續接收終端機輸入並傳送訊息。

    :param device_address: BLE 裝置的 MAC 地址 (如 "XX:XX:XX:XX:XX:XX")
    :param characteristic_uuid: 可寫入的 Characteristic UUID
    """
    try:
        print(f"嘗試連接裝置: {device_address}")
        async with BleakClient(device_address) as client:
            print(f"成功連接到 {device_address}")

            await client.get_services()
            characteristics = [char.uuid for service in client.services for char in service.characteristics]
            if characteristic_uuid not in characteristics:
                print(f"裝置不包含 Characteristic UUID: {characteristic_uuid}")
                return

            print("連接成功！現在可以輸入訊息。輸入 'exit' 結束。")

            while True:
                message = get_user_input()
                if message.lower() == "exit":
                    print("結束傳輸。")
                    break

                try:
                    encoded_message = message.encode('utf-8')
                    await client.write_gatt_char(characteristic_uuid, encoded_message)
                    print(f"訊息已發送: {message}")
                except Exception as e:
                    print(f"發送訊息時發生錯誤: {e}")

    except Exception as e:
        print(f"連接或傳輸時發生錯誤: {e}")

if __name__ == "__main__":
    device_address = input("請輸入裝置地址（如 XX:XX:XX:XX:XX:XX）：")
    characteristic_uuid = BT_UUID_CUSTOM_CHAR
    asyncio.run(send_message_to_ble_device(device_address, characteristic_uuid))
