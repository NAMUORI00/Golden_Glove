//Constants:
const int flexPin1 = 32; // 32
const int flexPin2 = 33; // 33
const int flexPin3 = 34; // 34
const int flexPin4 = 39; // VN
const int flexPin5 = 36; // VP

//Variables:
int value1, max_value1, min_value1; 
int value2, max_value2, min_value2; 
int value3, max_value3, min_value3; 
int value4, max_value4, min_value4; 
int value5, max_value5, min_value5; 

void setup(){
  Serial.begin(115200);       //Begin serial communication
  max_value1 = analogRead(flexPin1);         
  max_value2 = analogRead(flexPin2);         
  max_value3 = analogRead(flexPin3);         
  max_value4 = analogRead(flexPin4);         
  max_value5 = analogRead(flexPin5);

  min_value1 = 500;
  min_value2 = 500;
  min_value3 = 500;
  min_value4 = 400;
  min_value5 = 200;  
}

void loop(){
  value1 = map(analogRead(flexPin1), min_value1, max_value1, 0, 3);         
  value2 = map(analogRead(flexPin2), min_value2, max_value2, 0, 3);         
  value3 = map(analogRead(flexPin3), min_value3, max_value3, 0, 3);         
  value4 = map(analogRead(flexPin4), min_value4, max_value4, 0, 3);         
  value5 = map(analogRead(flexPin5), min_value5, max_value5, 0, 3);
         
  String tmp_msg1 = String(value1)+ ","; //32
  String tmp_msg2 = String(value2)+ ","; //33
  String tmp_msg3 = String(value3)+ ","; //34
  String tmp_msg4 = String(value4)+ ","; //VN
  String tmp_msg5 = String(value5)+ "/"; //VP / 는 전송 구분자
  String message = tmp_msg1 + tmp_msg2 + tmp_msg3 + tmp_msg4 + tmp_msg5;
  Serial.println(message);   

/*
  String v1 = String(analogRead(flexPin1))+",";         
  String v2 = String(analogRead(flexPin2))+",";         
  String v3 = String(analogRead(flexPin3))+",";         
  String v4 = String(analogRead(flexPin4))+",";         
  String v5 = String(analogRead(flexPin5))+"/"; 
  Serial.println(v1+v2+v3+v4+v5);  
*/
  delay(1000);                          
}
