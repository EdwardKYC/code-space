from nrf_command import send_message_to_ble_device
from config import connected_devices
def cancel_rasp_navigation():
    1
def cancel_device_navigation(device_id , color):
    """
    根據 device_name 查找 connected_devices 中的 MAC 地址，並傳送顏色訊息。

    :param device_name: 裝置的名稱
    :param color: 要設置的顏色
    """
    device = next((dev for dev in connected_devices.values() if dev.name == device_id), None)
    if device:
        mac_address = device.mac
        message = f"Cancel color:{color}"
        send_message_to_ble_device(mac_address, message)
        print(f"取消 {color}指令已傳送到裝置 {device_id}")
    else:
        print(f"[ERROR] 裝置名稱 {device_id} 不存在於 connected_devices 中。")

def add_rasp_direction():
    1
def add_device_color(device_id , color):
    device = next((dev for dev in connected_devices.values() if dev.name == device_id), None)
    if device:
        mac_address = device.mac
        message = f"Add color:{color}"
        send_message_to_ble_device(mac_address, message)
        print(f"已將顏色 {color} 傳送到裝置 {device_id}")
    else:
        print(f"[ERROR] 裝置 ID {device_id} 不存在於 connected_devices 中。")
