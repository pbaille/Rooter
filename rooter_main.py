import os
import socket
import serial
import csv
import time
from time import localtime, strftime
import matplotlib.pyplot as plt
import numpy as np
#from rooter_server import autoWaterCount1, autoWaterCount2, autoWaterCount6

os.system("lxterminal -e 'python3 rooter_server.py' &")


ser = serial.Serial('/dev/ttyACM0', 9600)
realTime = strftime("%d%m%y-%H%M", localtime())
hostname = socket.gethostname()    
IPAddr = socket.gethostbyname(hostname + ".local")
lightMode = ""
WateredHour1 = ""
WateredHour2 = ""
LastReset = strftime("%d %b - %H:%M", localtime())


"""
autoWaterCount1 = 0
autoWaterCount2 = 0
autoWaterCount6 = 0

autoWaterCount1 = repr(autoWaterCount1).encode('utf-8')
autoWaterCount2 = repr(autoWaterCount2).encode('utf-8')
autoWaterCount6 = repr(autoWaterCount6).encode('utf-8')
"""


#graph related:
ser.flushInput()

plot_window1 = 2160
y_var1 = np.array(np.zeros([plot_window1]))
fig1, ax1 = plt.subplots()
fig1.set_size_inches(5, 3)
line1, = ax1.plot(y_var1,color='red')
plt.ylabel('hPa')
plt.xlabel('Time (Last 3 days)')
#secaxy = ax.secondary_yaxis('right', (0, 8000))
plt.title("Barograph")
plt.ylim(990, 1040)
plt.xlim(0, 2160)
plt.grid(True)
plt.tight_layout()


plot_window2 = 2160
y_var2 = np.array(np.zeros([plot_window2]))
fig2, ax2 = plt.subplots()
fig2.set_size_inches(5, 3)
line2, = ax2.plot(y_var2,color='orange')
plt.ylabel('lux')
plt.xlabel('Time (Last 3 days)')
plt.title("Light-O-Graph")
plt.ylim(0, 10000)
plt.xlim(0, 2160)
plt.grid(True)
plt.tight_layout()

plot_window3 = 2160
y_var3 = np.array(np.zeros([plot_window3]))
fig3, ax3 = plt.subplots()
fig3.set_size_inches(5, 3)
line3, = ax3.plot(y_var3,color='blue')
plt.ylabel('Degrees Celsius')
plt.xlabel('Time (Last 3 days)')
plt.title("Temperature")
plt.ylim(10, 50)
plt.xlim(0, 2160)
plt.grid(True)
plt.tight_layout()

plot_window4 = 2160
y_var4 = np.array(np.zeros([plot_window4]))
fig4, ax4 = plt.subplots()
fig4.set_size_inches(5, 3)
line4, = ax4.plot(y_var4,color='green')
plt.ylabel('Percent')
plt.xlabel('Time (Last 3 days)')
plt.title("Air Humidity")
plt.ylim(0, 100)
plt.xlim(0, 2160)
plt.grid(True)
plt.tight_layout()

while True:
    while (ser.inWaiting()==0):
        pass
    data = ser.readline()
    dataSplit = data.split (' , '.encode())
    liveTime = strftime("%a %d %b %Y %H:%M", localtime())

    
    try:
        tempI =  dataSplit[0]
        tempIDec = float(tempI.decode('utf-8'))
        tempO =  dataSplit[1]
        tempODec = float(tempO.decode('utf-8'))
        humI =  dataSplit[2]
        humIDec = float(humI.decode('utf-8'))
        humO =  dataSplit[3]
        humODec = float(humO.decode('utf-8'))
        press =  dataSplit[4]
        pressDec = float(press.decode('utf-8'))
        light =  dataSplit[5]
        lightDec = float(light.decode('utf-8'))
        sensor1 =  dataSplit[6]
        sensor1Dec = float(sensor1.decode('utf-8'))
        sensor2 =  dataSplit[7]
        sensor2Dec = float(sensor2.decode('utf-8'))
        lightTime = strftime("%H%M", localtime())
        lightTime = int(lightTime)
        
        #autoWaterCount1 = repr(autoWaterCount1).encode('utf-8')
        #autoWaterCount1 = float(autoWaterCount1.decode('utf-8'))
        #autoWaterCount1 = autoWaterCount1.encode()

        #autoWaterCount2 = repr(autoWaterCount2).encode('utf-8')
        #autoWaterCount2 = float(autoWaterCount2.decode('utf-8'))
        #autoWaterCount2 = autoWaterCount2.encode()

        #autoWaterCount6 = repr(autoWaterCount6).encode('utf-8')
        #autoWaterCount6 = float(autoWaterCount6.decode('utf-8'))
        #autoWaterCount6 = autoWaterCount6.encode()

    except:
            continue

    #HTML part

    with open('templates/index.html','wb') as e:
            htmlBlock = """<!doctype html>\n
                         <html>\n<head>\n<title>\nThe ROOTER\n</title>\n<meta http-equiv="refresh" content="300" >
                         \n<link rel="stylesheet" href="/static/style.css" />\n</head>\n<body>\n<h1>\n
                         <reduce>\n--------------------------------------------------------------\n</reduce>\n
                         <br>\nThe ROOTER v2.1\n<br>\n<reduce>\n---------------&nbsp;&nbsp;
                         """
            e.write(htmlBlock.encode())
            e.write(liveTime.encode())
            htmlBlock = """
                        &nbsp;&nbsp;---------------\n</reduce>\n</h1>\n<center>\n<table>\n<tr>\n<td>\n<right>
                        Temperature (in/out):&nbsp;&nbsp;&nbsp;\n</right>\n</td>\n<td>\n<left>
                        """
            e.write(htmlBlock.encode())
            e.write(tempI)
            e.write(' °C&nbsp;&nbsp;/&nbsp;&nbsp;'.encode())
            e.write(tempO)
            htmlBlock = """
                         °C</left>\n</td>\n</tr>\n<tr>\n<td>\n<right>\nHumidity (in/out):&nbsp;&nbsp;&nbsp;
                         \n</right>\n</td>\n<td>\n<left>\n
                        """
            e.write(htmlBlock.encode())
            e.write(humI)
            e.write(' %&nbsp;&nbsp;/&nbsp;&nbsp;'.encode())
            e.write(humO)
            htmlBlock = """
                         %</left>\n</td>\n</tr>\n<tr>\n<td>\n<right>Pressure:&nbsp;&nbsp;&nbsp;\n</right>\n
                         </td>\n<td>\n<left>
                        """
            e.write(htmlBlock.encode())
            e.write(press)
            htmlBlock = """
                         hPa\n</left>\n</td>\n</tr>\n<tr>\n<td>\n<right>\nLight:&nbsp;&nbsp;&nbsp;\n</right>\n
                        </td>\n<td>\n<left>
                        """
            e.write(htmlBlock.encode())
            e.write(light)
            htmlBlock = """
                         lux\n</left>\n</td>\n</tr>\n<tr>\n<td>\n<br>\n</td>\n<td>\n</td>\n</tr>\n<tr>\n<td>\n
                         <largetxt>\n1 - Basilic:&nbsp;&nbsp;\n</largetxt>\n</td>\n<td>\n<largetxt>\n
                        """
            e.write(htmlBlock.encode())

            if sensor1Dec >= 80:
                e.write('<blue>'.encode())
                e.write(sensor1)
                e.write(' %'.encode())
                e.write('</blue>'.encode())
            elif sensor1Dec >= 55 and sensor1Dec < 80:
                e.write('<green>'.encode())
                e.write(sensor1)
                e.write(' %'.encode())
                e.write('</green>'.encode())
            elif sensor1Dec >= 45 and sensor1Dec < 55:
                e.write('<yellow>'.encode())
                e.write(sensor1)
                e.write(' %'.encode())
                e.write("""</yellow>&nbsp;&nbsp;&nbsp;&nbsp;<button onclick="func_Water1()">Water</button>

                        <script>
                        function func_Water1() {
                          var popup = window.open("/water-11/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>""".encode())
            elif sensor1Dec >= 40 and sensor1Dec < 45:
                e.write('<red>'.encode())
                e.write(sensor1)
                e.write(""" %</red>&nbsp;&nbsp;&nbsp;&nbsp;<button onclick="func_Water11()">Water</button>

                        <script>
                        function func_Water11() {
                          var popup = window.open("/water-11/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>""".encode())

            elif sensor1Dec < 40:
                e.write('<red>'.encode())
                e.write(sensor1)
                os.system('curl http://192.168.20.145/VALVE=14')
                WateredHour1 = strftime("%d/%m - %H:%M", localtime())
                #autoWaterCount1 += 1

            e.write('</largetxt>&nbsp;&nbsp;Last watered:&nbsp;'.encode())
            e.write(WateredHour1.encode())
            """
            autoWaterCount1 = repr(autoWaterCount1).encode('utf-8')
            e.write(autoWaterCount1)
            autoWaterCount1 = int(autoWaterCount1)
            """
            e.write('\n</td>\n</tr>\n<tr>\n<td>\n<largetxt>\n2 - Origan / Thym:&nbsp;&nbsp;\n</largetxt>\n</td>\n<td>\n<largetxt>\n'.encode())



            if sensor2Dec >= 80:
                e.write('<blue>'.encode())
                e.write(sensor2)
                e.write(' %'.encode())
                e.write('</blue>'.encode())
            elif sensor2Dec >= 55 and sensor2Dec < 80:
                e.write('<green>'.encode())
                e.write(sensor2)
                e.write(' %'.encode())
                e.write('</green>'.encode())
            elif sensor2Dec >= 45 and sensor2Dec < 55:
                e.write('<yellow>'.encode())
                e.write(sensor2)
                e.write(' %'.encode())
                e.write("""</yellow>&nbsp;&nbsp;&nbsp;&nbsp;<button onclick="func_Water21()">Water</button>

                        <script>
                        function func_Water21() {
                          var popup = window.open("/water-21/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>""".encode())
            elif sensor2Dec >= 40 and sensor2Dec < 45:
                e.write('<red>'.encode())
                e.write(sensor2)
                e.write(""" %</red>&nbsp;&nbsp;&nbsp;&nbsp;<button onclick="func_Water21()">Water</button>

                        <script>
                        function func_Water21() {
                          var popup = window.open("/water-21/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>""".encode())

            elif sensor2Dec < 40:
                e.write('<red>'.encode())
                e.write(sensor2)
                os.system('curl http://192.168.20.145/VALVE=24')
                WateredHour2 = strftime("%d/%m - %H:%M", localtime())
                #autoWaterCount2 += 1

            e.write('\n</largetxt>\n&nbsp;&nbsp;Last watered:&nbsp;'.encode())
            e.write(WateredHour2.encode())
            """
            autoWaterCount2 = repr(autoWaterCount2).encode('utf-8')
            e.write(autoWaterCount2)
            autoWaterCount2 = int(autoWaterCount2)
            """
            htmlBlock = """\n</td>\n</tr>\n</table>\n</center>\n<p id="demo">\n</p>\n<br>\n<br>\n<p>\n
                        <img src="static/pressure.png" style="width:333px;height:200px;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <img src="static/tempin.png" style="width:333px;height:200px;">
                        <br><br>
                        <img src="static/light.png" style="width:333px;height:200px;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <img src="static/humin.png" style="width:333px;height:200px;">
                        \n</p>
                        """
            e.write(htmlBlock.encode())
            htmlBlock = """

                        <button onclick="func_Water11()">Water 1 - 1L</button>

                        <script>
                        function func_Water11() {
                          var popup = window.open("/water-11/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        <button onclick="func_Water21()">Water 2 - 1L</button>

                        <script>
                        function func_Water21() {
                          var popup = window.open("/water-21/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        <button onclick="func_Water31()">Water 3 - 1L</button>

                        <script>
                        function func_Water31() {
                          var popup = window.open("/water-31/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water41()">Water 4 - 1L</button>

                        <script>
                        function func_Water41() {
                          var popup = window.open("/water-41/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water51()">Water 5 - 1L</button>

                        <script>
                        function func_Water51() {
                          var popup = window.open("/water-51/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water61()">Water 6 - 1L</button>

                        <script>
                        function func_Water61() {
                          var popup = window.open("/water-61/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        <br>

                        <button onclick="func_Water14()">Water 1 - 4L</button>

                        <script>
                        function func_Water14() {
                          var popup = window.open("/water-14/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        <button onclick="func_Water24()">Water 2 - 4L</button>

                        <script>
                        function func_Water24() {
                          var popup = window.open("/water-24/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        <button onclick="func_Water34()">Water 3 - 4L</button>

                        <script>
                        function func_Water34() {
                          var popup = window.open("/water-34/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water44()">Water 4 - 4L</button>

                        <script>
                        function func_Water44() {
                          var popup = window.open("/water-44/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water54()">Water 5 - 4L</button>

                        <script>
                        function func_Water54() {
                          var popup = window.open("/water-54/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>
                        
                        <button onclick="func_Water64()">Water 6 - 4L</button>

                        <script>
                        function func_Water64() {
                          var popup = window.open("/water-64/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>


                        <br>
                        <br>

                        <button onclick="func_led1On()">LED1 - ON</button>

                        <script>
                        function func_led1On() {
                          var popup = window.open("/LED1_ON/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        
                        <button onclick="func_led1Off()">LED1 - OFF</button>

                        <script>
                        function func_led1Off() {
                          var popup = window.open("/LED1_OFF/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>


                        <br>

                        
                        <button onclick="func_fan1On()">FAN1 - ON</button>

                        <script>
                        function func_fan1On() {
                          var popup = window.open("/FAN1_ON/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>

                        
                        <button onclick="func_fan1Off()">FAN1 - OFF</button>

                        <script>
                        function func_fan1Off() {
                          var popup = window.open("/FAN1_OFF/", "Popup", "width=200,height=200");
                          setTimeout(function() {
                          popup.close();
                          }, 200);
                        }
                        </script>




                        <br>\n
                        
                        <br>\n
                        
                        <br>\n

                        <em>Last reset: 
                        

                        """

                       
            e.write(htmlBlock.encode())
            e.write(LastReset.encode())
            e.write('\n</em>\n<br>\n<br>\n<br>\n</body>\n</html>\n'.encode())


          
            """
            autoWaterCount6 = autoWaterCount6.decode('utf-8')
            e.write(autoWaterCount6)
            e.write('\n</body>\n</html>\n'.encode())
            """
 
            e.close()
    
    
    with open('smartgarden.csv','a') as f:  #   ('smartgarden' + realTime + '.csv','a') as f:
        writer = csv.writer(f,delimiter=",")
        writer.writerow([
            strftime("%m/%d %H:%M", localtime()),  #strftime("%m/%d %H:%M", localtime())
            tempIDec,
            humIDec,
            tempODec,
            humODec,
            pressDec,
            lightDec,
            sensor1Dec,
            sensor2Dec
        ])    
    
    
    
    if lightMode != "evening" and lightMode != "night" and lightMode != "morning" and lightDec <= 90:
        lightMode = "evening"
        os.system('curl http://192.168.20.138/LED=ONOFF')

    elif lightMode != "night" and lightTime >= 2300 and lightTime <= 2305:
        lightMode = "night"
        os.system('curl http://192.168.20.138/LED=ONOFF')

    elif lightMode != "morning" and lightTime >= 500 and lightTime <= 505:
        lightMode = "morning"
        os.system('curl http://192.168.20.138/LED=ONOFF')

    elif lightMode != "day" and lightDec >= 110:
        lightMode = "day"
        os.system('curl http://192.168.20.138/LED=ONOFF')




    os.system('clear')   
    print()
    print('SMART GARDEN ENABLED')    
    print()
    print("Check your Rooter at http://" + IPAddr + ":5000")  
    print() 
    print("lightMode: ", lightMode)
    print("lightTime: ", lightTime)
    #print(autoWaterCount6.decode('utf-8'))


    ser.write(IPAddr.encode()) 

   
    #graph related:
    y_var1 = np.append(y_var1,pressDec)
    y_var1 = y_var1[1:plot_window1+1]
    line1.set_ydata(y_var1)
    ax1.set_xticklabels([])
    #ax1.relim()
    #ax1.autoscale_view()
    fig1.canvas.draw()
    fig1.savefig('static/pressure.png')
    fig1.canvas.flush_events()

    y_var2 = np.append(y_var2,lightDec)
    y_var2 = y_var2[1:plot_window2+1]
    line2.set_ydata(y_var2)
    ax2.set_xticklabels([])
    #ax2.relim()
    #ax2.autoscale_view()
    fig2.canvas.draw()
    fig2.savefig('static/light.png')
    fig2.canvas.flush_events()

    y_var3 = np.append(y_var3,tempIDec)
    y_var3 = y_var3[1:plot_window3+1]
    line3.set_ydata(y_var3)
    ax3.set_xticklabels([])
    #ax3.relim()
    #ax3.autoscale_view()
    fig3.canvas.draw()
    fig3.savefig('static/tempin.png')
    fig3.canvas.flush_events()

    y_var4 = np.append(y_var4,humIDec)
    y_var4 = y_var4[1:plot_window4+1]
    line4.set_ydata(y_var3)
    ax4.set_xticklabels([])
    #ax4.relim()
    #ax4.autoscale_view()
    fig4.canvas.draw()
    fig4.savefig('static/humin.png')
    fig4.canvas.flush_events()



    
