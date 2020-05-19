import bluetooth
import serial                                      
import pyautogui   
import time                              
Arduino_Serial = serial.Serial('com3',9600)     
 
while 1:
    incoming_data = str (Arduino_Serial.readline())
                  

    if 'previous' in incoming_data:                  
        pyautogui.hotkey('ctrl', 'pgdn')          
        
    if 'next' in incoming_data:              
        pyautogui.hotkey('ctrl', 'pgup')         

    if 'down' in incoming_data:                    
        pyautogui.press('down')                  
        pyautogui.scroll(-100) 
         
    if 'up' in incoming_data:                    
        pyautogui.press	('up')                     
        pyautogui.scroll(100)
			
    if 'change' in incoming_data:                 
        pyautogui.keyDown('alt')                  
        pyautogui.press('tab')
        pyautogui.keyUp('alt')
		
    if 'nothing' in incoming_data:
	    pyautogui.hotkey('ctrl','1')
        
    incoming_data = "";