// ------------------- 马达引脚定义 -------------------
const int motor1_A = 2;  // 马达1（高音）接 L9110S A-1A
const int motor1_B = 4;  // 马达1 接 A-1B
const int motor2_A = 5;  // 马达2（低音）接 L9110S B-1A
const int motor2_B = 18; // 马达2 接 B-1B

// ------------------- 按钮引脚定义（GPIO19） -------------------
const int buttonPin = 19;  // 按钮一端接GPIO19，另一端接GND
bool hasPlayed = false;    // 播放标记：防止重复播放

// ------------------- 蜂鸣器标准音符频率表 -------------------
// ------------------- 3个完整八度 蜂鸣器标准音符频率表 -------------------
// 第1个八度：低音八度（C3 - B3，低沉音调，适合马达2低音部）
#define NOTE_C3  131  // 低音Do
#define NOTE_D3  147  // 低音Re
#define NOTE_E3  165  // 低音Mi
#define NOTE_F3  175  // 低音Fa
#define NOTE_G3  196  // 低音So
#define NOTE_A3  220  // 低音La
#define NOTE_B3  247  // 低音Si

// 第2个八度：中音八度（C4 - B4，基准音调，双马达同步/主旋律）
#define NOTE_C4  262  // 中央Do
#define NOTE_D4  294  // 中音Re
#define NOTE_E4  330  // 中音Mi
#define NOTE_F4  349  // 中音Fa
#define NOTE_G4  392  // 中音So
#define NOTE_A4  440  // 中音La
#define NOTE_B4  494  // 中音Si

// 第3个八度：高音八度（C5 - B5，尖锐音调，适合马达1高音部）
#define NOTE_C5  523  // 高音Do
#define NOTE_D5  587  // 高音Re
#define NOTE_E5  659  // 高音Mi
#define NOTE_F5  698  // 高音Fa
#define NOTE_G5  784  // 高音So
#define NOTE_A5  880  // 高音La
#define NOTE_B5  988  // 高音Si

// 节拍参数（控制速度）
#define BPM 120        // 每分钟节拍数（可调整：90=慢，150=快）
#define QUARTER_NOTE 1 // 四分音符
#define EIGHTH_NOTE 0.5// 八分音符

// PWM配置（占空比50%，声音模拟蜂鸣器）
const int PWM_DUTY = 128;  // 0-255，128=50%占空比

void setup() {
  // 马达引脚初始化
  pinMode(motor1_A, OUTPUT);
  pinMode(motor1_B, OUTPUT);
  pinMode(motor2_A, OUTPUT);
  pinMode(motor2_B, OUTPUT);
  
  //按钮引脚初始化（内部上拉，稳定防抖动）
  pinMode(buttonPin, INPUT_PULLUP);
  
  // 初始停止
  motorStop(1);
  motorStop(2);
}

void loop() {
  // 按键检测
  int btnState = digitalRead(buttonPin);
  
  // 按钮按下（INPUT_PULLUP模式下，按下为LOW）且未播放过
  if (btnState == LOW && !hasPlayed) {
    delay(20);  // 简单消抖，过滤机械抖动
    if (digitalRead(buttonPin) == LOW) { // 再次确认按下
      playYourBadApple(); // 播放你原有的音乐（一遍即停）
      hasPlayed = true;   // 标记已播放，防止按住重复触发
    }
  }
  
  // 按钮松开后，重置标记，允许下次点击
  if (btnState == HIGH) {
    hasPlayed = false;
  }
}

// Bad Apple!
void playYourBadApple() {
  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  playTone(0, NOTE_D3, QUARTER_NOTE);  // 低音Re（2）
  delay(50); // 小节间隔

  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  delay(50); // 小节间隔

  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_C3, EIGHTH_NOTE);   // 低音Do（1）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  delay(40); // 小节间隔

  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  playTone(0, NOTE_D3, QUARTER_NOTE);  // 低音Re（2）
  delay(50); // 小节间隔

  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  delay(50); // 小节间隔

  playTone(0, NOTE_D3, EIGHTH_NOTE);   // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, QUARTER_NOTE);  // 低音Mi（3）
  playTone(0, NOTE_F3, QUARTER_NOTE);  // 低音Fa（4）
  playTone(0, NOTE_G3, QUARTER_NOTE);  // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔
 
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_C3, EIGHTH_NOTE);   // 低音Do（1）
  playTone(0, NOTE_D3, QUARTER_NOTE);  // 低音Re（2）
  delay(50); // 小节间隔

  playTone(0, NOTE_C3, EIGHTH_NOTE);   // 低音Do（1）
  playTone(0, NOTE_D3, EIGHTH_NOTE);  // 低音Re（2）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_D3, QUARTER_NOTE);  // 低音Re（2）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, QUARTER_NOTE);  // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_E4, EIGHTH_NOTE);   // 中音Mi（3）
  playTone(0, NOTE_G4, EIGHTH_NOTE);   // 中音So（5）
  playTone(0, NOTE_E4, EIGHTH_NOTE);   // 中音Mi（3）
  playTone(0, NOTE_D4, EIGHTH_NOTE);   // 中音Re（2）
  playTone(0, NOTE_C4, EIGHTH_NOTE);   // 中音Do（1）
  playTone(0, NOTE_A3, QUARTER_NOTE);   // 低音La（6）
  delay(50); // 小节间隔

  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_A3, EIGHTH_NOTE);   // 低音La（6）
  playTone(0, NOTE_G3, EIGHTH_NOTE);   // 低音So（5）
  playTone(0, NOTE_F3, EIGHTH_NOTE);   // 低音Fa（4）
  playTone(0, NOTE_E3, EIGHTH_NOTE);   // 低音Mi（3）
  playTone(0, NOTE_C3, EIGHTH_NOTE);   // 低音Do（1）
  playTone(0, NOTE_D3, QUARTER_NOTE);  // 低音Re（2）
  delay(50); // 小节间隔



  // 播放结束后强制停止马达
  motorStop(1);
  motorStop(2);
}

// ------------------- 播放单个音符（核心：高频PWM连续驱动） -------------------
// motorNum: 1=马达1 2=马达2 0=双马达同步
// freq: 音符频率（Hz）
// duration: 节拍时长
void playTone(int motorNum, int freq, float duration) {
  int noteTime = (60000 / BPM) * duration;  // 音符播放时间（毫秒）
  int pulseTime = 1000000 / (2 * freq);     // PWM脉冲半周期（微秒），模拟高频振动
  
  // 连续输出高频PWM，模拟蜂鸣器连续音
  unsigned long start = millis();
  while (millis() - start < noteTime - 50) {  // 减去50ms间隔，避免连音
    if (motorNum == 1 || motorNum == 0) {
      digitalWrite(motor1_A, HIGH);
      delayMicroseconds(pulseTime);
      digitalWrite(motor1_A, LOW);
      delayMicroseconds(pulseTime);
    }
    if (motorNum == 2 || motorNum == 0) {
      digitalWrite(motor2_A, HIGH);
      delayMicroseconds(pulseTime);
      digitalWrite(motor2_A, LOW);
      delayMicroseconds(pulseTime);
    }
  }
  
  // 音符间隔（避免粘连）
  motorStop(1);
  motorStop(2);
  delay(50);
}

// ------------------- 马达停止 -------------------
void motorStop(int motorNum) {
  if (motorNum == 1 || motorNum == 0) {
    digitalWrite(motor1_A, LOW);
  }
  if (motorNum == 2 || motorNum == 0) {
    digitalWrite(motor2_A, LOW);
  }
}