import time
import schedule
import requests

def scan_bluetooth():
    try:

        response = requests.get("http://your-rigado-gateway-ip/api/scan") 
        if response.status_code == 200:
            print("掃描成功")
            print(response.json()) 
    except Exception as e:
        print(f"掃描時發生錯誤: {e}")

schedule.every(10).seconds.do(scan_bluetooth)

while True:
    schedule.run_pending()
    time.sleep(1)