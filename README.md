第一部分用digitalin來把三個按鈕訊號輸入
接著根據按鈕輸入值來決定uLCD的輸出，在此碰到了技術性的問題，到目前還是沒法解決，就是其中一個按鈕明明看起來條件跟其他兩個一樣，卻會讓整個程式失靈，而且只要移除該按鈕的lcd指令就又恢復正常了，十分弔詭。
為了避免不同步，採用兩個thread來同時進行sample跟generate波型的指令
最後用FFT.py來畫圖，修改了幾個變數以符合波的頻率，但平均5次才會成功畫出一次。
