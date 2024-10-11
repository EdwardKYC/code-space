const express = require("express"); //引入Express
const app = express(); //使用Express

app.listen(80,function(){ //讓這個網頁伺服器開在80埠口
    console.log("Server Start!") //開啟成功後輸出這一行
})
app.get('/',function(req,res){//在根路徑的時候回應
    //req代表request
    //res代表respond
    res.send("Hello World!!");
})