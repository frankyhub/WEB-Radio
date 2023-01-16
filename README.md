# WEB-Radio
Dieses Repository beschreibt den Aufbau eines WEB Radios. Über einen Drehgeber Encoder sind 20 Radiostationen wählbar. 
Die Lautstärke wird direkt über das Poti am Audio-Verstärker eingestellt. Das LCD-Display zeigt die gewählte Radio-Station 
an und kann über einen WEB-Server abgerufen und verändert werden. Nach dem Einschalten über den Volume-Regler/Schalter sucht 
der Mikrocontroller nach einer gültigen WLAN-Verbindung und stellt die zuletzt gewählte Radio-Station ein. Liegt keine gültige 
WLAN-Verbindung vor, startet der WLAN-Manager. Über die Netzwerkeinstellung des Handys/Tablet kann nach der Auswahl „WEBRADIO“ 
der WLAN-Manager mit der IP-Adresse 192.168.4.1 aufgerufen werden. Über den WLAN-Manager ist die eigene WLAN-Verbindung speicherbar.
Nach dem speichern der Zugangsdaten startet der Mikrocontroller neu und das LCD-Display zeigt die IP-Adresse des WEB-Servers und 
danach die gewählte Radio-Station an. Viele Radiosender können als MP3-Stream über das Internet gehört werden. In dieser Version 
sind 20 Radio-Sender gespeichert und sind über den WEB-Server veränderbar.

![webradio1](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/webradio.jpg)



WEB-Radio WiFi-Einstellung


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/WEBRADIO_AP1.png)


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/WEBRADIO_AP3.png)



WEB-Radio LCD Display


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/webradio1.JPG)


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/webradio2.JPG)



WEB-Radio Senderliste


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/webradio-sender.png)



WEB-Radio Verdrahtung


![webradio2](https://github.com/frankyhub/WEB-Radio/blob/main/Pics/webradio_fritzing_gr.jpg)





