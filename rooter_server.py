from flask import Flask, render_template
#represent le 06 gro
import os
#from smartGarden import autoWaterCount6

app = Flask(__name__)

autoWaterCount6 = 3
autoWaterCount1 = 0
autoWaterCount2 = 0
"""
autoWaterCount6 = 3
autoWaterCount1 = repr(autoWaterCount1).encode('utf-8')
autoWaterCount2 = repr(autoWaterCount2).encode('utf-8')
autoWaterCount6 = repr(autoWaterCount6).encode('utf-8')
"""


@app.route('/')
def index():
    return render_template('index.html')


"""
@app.route('/my-link/')
def my_link():
  os.system('curl http://192.168.20.145/VALVE=4')
  os.system('clear')
  return ''
"""

@app.route('/water-11/')
def water_11():
  os.system('curl http://192.168.20.145/VALVE=11')
  os.system('clear')
  return ''

@app.route('/water-21/')
def water_21():
  os.system('curl http://192.168.20.145/VALVE=21')
  os.system('clear')
  return ''

@app.route('/water-31/')
def water_31():
  os.system('curl http://192.168.20.145/VALVE=31')
  os.system('clear')
  return ''

@app.route('/water-41/')
def water_41():
  os.system('curl http://192.168.20.145/VALVE=41')
  os.system('clear')
  return ''

@app.route('/water-51/')
def water_51():
  os.system('curl http://192.168.20.145/VALVE=51')
  os.system('clear')
  return ''

@app.route('/water-61/')
def water_61():
  os.system('curl http://192.168.20.145/VALVE=61')
  os.system('clear')
  global autoWaterCount6
  autoWaterCount6 += 1
  #autoWaterCount6 = repr(autoWaterCount6).encode('utf-8')
  #autoWaterCount6 = autoWaterCount6.decode('utf-8')
  print(autoWaterCount6)
  return ''

@app.route('/water-14/')
def water_14():
  os.system('curl http://192.168.20.145/VALVE=14')
  os.system('clear')
  return ''

@app.route('/water-24/')
def water_24():
  os.system('curl http://192.168.20.145/VALVE=24')
  os.system('clear')
  return ''

@app.route('/water-34/')
def water_34():
  os.system('curl http://192.168.20.145/VALVE=34')
  os.system('clear')
  return ''

@app.route('/water-44/')
def water_44():
  os.system('curl http://192.168.20.145/VALVE=44')
  os.system('clear')
  return ''

@app.route('/water-54/')
def water_54():
  os.system('curl http://192.168.20.145/VALVE=54')
  os.system('clear')
  return ''

@app.route('/water-64/')
def water_64():
  os.system('curl http://192.168.20.145/VALVE=64')
  os.system('clear')
  return ''


@app.route('/LED1_ON/')
def led1On():
  os.system('curl http://192.168.20.145/LED1=ON')
  os.system('clear')
  return ''

@app.route('/LED1_OFF/')
def led1Off():
  os.system('curl http://192.168.20.145/LED1=OFF')
  os.system('clear')
  return ''

@app.route('/LED2_ON/')
def led2On():
  os.system('curl http://192.168.20.145/LED2=ON')
  os.system('clear')
  return ''
  
@app.route('/LED2_OFF/')
def led2Off():
  os.system('curl http://192.168.20.145/LED2=OFF')
  os.system('clear')
  return ''


@app.route('/FAN1_ON/')
def fan1On():
  os.system('curl http://192.168.20.145/FAN1=ON')
  os.system('clear')
  return ''
  
@app.route('/FAN1_OFF/')
def fan1Off():
  os.system('curl http://192.168.20.145/FAN1=OFF')
  os.system('clear')
  return ''

@app.route('/FAN2_ON/')
def fan2On():
  os.system('curl http://192.168.20.145/FAN2=ON')
  os.system('clear')
  return ''
  
@app.route('/FAN2_OFF/')
def fan2Off():
  os.system('curl http://192.168.20.145/FAN2=OFF')
  os.system('clear')
  return ''








if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
