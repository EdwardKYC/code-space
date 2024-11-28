import tkinter as tk

# 建立應用程式視窗
root = tk.Tk() #建立一個主視窗物件 root
root.title("方向鍵顯示")
root.attributes("-fullscreen", True) #視窗設置為全螢幕顯示

# 顯示方向的標籤
direction_label = tk.Label(root, text="", font=("Arial", 200))
direction_label.pack(expand=True) #讓標籤自動擴展以填充可用空間

# 處理方向鍵按下的函數
def show_direction(event):
    key_directions = {
        "Up": "↑ ",
        "Down": "↓ ",
        "Left": "← ",
        "Right": "→ "
    }
    direction = key_directions.get(event.keysym, "") #根據按鍵名稱從 key_directions 中獲取相應文字，若找不到對應的按鍵名稱，則回傳空字串。
    direction_label.config(text=direction)

def exit_fullscreen(event): # 綁定 Escape 鍵退出全螢幕
    root.attributes("-fullscreen", False)

# 綁定方向鍵事件
root.bind("<Up>", show_direction)
root.bind("<Down>", show_direction)
root.bind("<Left>", show_direction)
root.bind("<Right>", show_direction)
root.bind("<Escape>", exit_fullscreen) 

# 運行主循環
root.mainloop()
