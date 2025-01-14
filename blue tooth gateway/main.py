from bleak import BleakClient
import asyncio

async def send_message_to_ble_device(device_address, characteristic_uuid, message):
    """
    連線到 BLE 裝置並傳送訊息。

    :param device_address: BLE 裝置的 MAC 地址 (如 "XX:XX:XX:XX:XX:XX")
    :param characteristic_uuid: 可寫入的 Characteristic UUID
    :param message: 要傳送的訊息 (字串)
    """
    try:
        print(f"嘗試連接裝置: {device_address}")
        async with BleakClient(device_address) as client:
            print(f"成功連接到 {device_address}")
            
            # 檢查裝置是否有該 Characteristic
            if characteristic_uuid in client.services.characteristics:
                print(f"發送訊息到 Characteristic: {characteristic_uuid}")
                
                # 寫入訊息
                await client.write_gatt_char(characteristic_uuid, message.encode('utf-8'))
                print(f"訊息已成功發送: {message}")
            else:
                print(f"裝置不包含 Characteristic UUID: {characteristic_uuid}")
    except Exception as e:
        print(f"連接或傳輸時發生錯誤: {e}")

# 使用範例
if __name__ == "__main__":
    device_address = "XX:XX:XX:XX:XX:XX"  # 替換為目標裝置的 MAC 地址
    characteristic_uuid = "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX"  # 替換為可寫入的 Characteristic UUID
    message = "Hello, BLE!"
    
    asyncio.run(send_message_to_ble_device(device_address, characteristic_uuid, message))
