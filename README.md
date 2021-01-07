# SMART HELMET DESIGN :droplet:
code for smart helmet lock

# PROGRAM LOAD GUIDE :hammer:

# IDE Installation :white_check_mark:
1) To download the ide used for this program find the IDE from here :link: [Arduino IDE](https://www.arduino.cc/en/software) 
2) Once you have downloaded the program proceed to the next step

# Download the Files :arrow_down_small:
3) From this repo click on the download option at the code :arrow_double_down: 
4) From the master you will find two files, code is on the file :file_folder: "smart_helmet_lock" and the "libraries folder"

# Library Installation
5) Copy the library as a folder to your documents -> arduino -> libraries once you complete you are done with the initial software preparations 
6) To familiarise yourself with the IDE use this tutorial :high_brightness: :link: [Tutorial](https://www.youtube.com/watch?v=nL34zDTPkcs&t=3s) 

# Burning bootload to the MCU :fire:
1) To do this you will need an older version of the arduino particularly version 1.6.9 find it here :link: [Old SoftwareReleases Arduino IDE](https://www.arduino.cc/en/main/OldSoftwareReleases)
2) Once you have it setup to burn the bootloader follow this tutotial :link: [Burining Arduino Bootloader] (https://www.youtube.com/watch?v=Kh4iZb2YTT8&t=337s) 

# Uploading the codes  :arrow_up:

You can buy the USBASP from here :link: [buy usbasp] (https://aliexpress.ru/af/USBASP-USBISP-AVR-Programmer-USB.html?catId=0&d=y&aff_platform=portals-tool&initiative_id=SB_20201020044645&origin=n&sk=_9JHld5&aff_trace_key=4b1704d992da43b586041dfb7cd31d7e-1606574782769-00350-_9JHld5&SearchText=USBASP%2BUSBISP%2BAVR%2BProgrammer%2BUSB&terminal_id=351d58321dfa473cb106b58978d7c19c)
or here 
 :link: [buy usbasp](https://aliexpress.ru/item/32649685244.html?spm=a2g0o.productlist.0.0.22e26eaf2mIeLt&algo_pvid=b6506204-320d-4244-9d76-c7a1c32c5ee5&algo_expid=b6506204-320d-4244-9d76-c7a1c32c5ee5-16&btsid=0b8b036a16065747853274219e2939&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

1) Insert the ISP programmer cable socket onto ISP header. ...
2) Open Arduino IDE software. ...
3) Next, call out any example of source code. ...
4) Select “USBasp” from the Tools > Programmer menu.
5) Select “Upload using Programmer” from the File menu.

You can also explore more from the following tutorial :link:[How to Use USBasp Programmer with Arduino Boards](https://www.youtube.com/watch?v=ToKerwRR-70)

# HANDLING THE BLUETOOTH APP & ARDUINO CODES :hammer:
1) Ensure that the app connects to the system / our device
2) Once a connection is established, on the specific app you can send a certain text or number or what the app has catered for transmission
3) In our codes we have catered for sending "1" to activate the system just 1 with no "" 
4) If this is successfully send you should see trigger on the specific pin

