class VerySimpleSequencer {
public:
  boolean pattern_end;

  void init () {
    running = false;

    setBPM (100);
    triggered = false;


    for (int i=0; i<64; i++) {
      step_seq [i]="";
    }

  }

  void start () {
    running = true;
    time_keeper = millis ();

    triggered = false;
  }
  void stop () {
    running = false;
    // mute

  }
  void startFeed () {
    step_seq_counter = 0;
    for (int i=0; i<64; i++) {
      step_seq [i] = "\0";
    }
  }
  void addStep (char * seq) {
    Serial.print ("====");
    Serial.print (seq);
    Serial.println (">");

    step_seq [step_seq_counter++] = seq;
  }
  
  void resync (int pin) {
    beat = 0;
    
    digitalWrite (pin, HIGH);
    time_keeper = millis ();
    digitalWrite (pin, LOW);
  }

  String step () {
    String s = "";
    
    pattern_end = false;
    
    if (running) {

      if (millis ()-time_keeper>=click_16) {
        if (!triggered) {  
          s = step_seq [beat];
          //Serial.println (s);

          if (beat<step_seq_counter-1) beat++;
          //if (beat<64) beat++;
          else {
            pattern_end = true;
            beat = 0;
          }

          // check if has L
          int v = s.indexOf ("L");
          if (v>0) {
            velocity_counter = long_velocity;
            s = s.substring (0, s.length ()-1);
          }  
          else {
            velocity_counter = short_velocity;
          }

          // mark triggered
          triggered = true;


          velocity_keeper = time_keeper = millis ();
        } 
        else {

        }
      }

      if (triggered) {
        if (millis ()-velocity_keeper>=velocity_counter) {
          triggered = false;
          s = ".";
        }
      }

      return s;
    } 
    else {
      return ".";
    }
  }
  
  

  void setBPM (int _bpm) {
    bpm = _bpm;
    setMeasures ();
  }
  void setMeasures () {
    click_4 = int ((60.0f/float (bpm))*1000);
    click_8 = int ((30.0f/float (bpm))*1000);
    click_16 = int ((15.0f/float (bpm))*1000);

    long_velocity = click_16;
    short_velocity = click_16/4;
  }




  ///////////////////////////////////////////////////
  //************************************************
  
  void ptn_calib () {
    step_seq [0] = ".";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = ".";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";
    
    step_seq_counter = 16;
  }


  void ptn_noise () {

    step_seq [0] = "C5";

    step_seq [1] = ".";

    step_seq [2] = "C8";

    step_seq [3] = "s";

    step_seq [4] = "S";

    step_seq [5] = ".";

    step_seq [6] = "s";

    step_seq [7] = "A7";

    step_seq [8] = "S";

    step_seq [9] = ".";

    step_seq [10] = "s";

    step_seq [11] = "C8";

    step_seq [12] = "S";

    step_seq [13] = ".";

    step_seq [14] = "s";

    step_seq [15] = "s";

    step_seq_counter = 16;

  }


  void ptn_inv01 () {

    step_seq [0] = "S";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = "s";

    step_seq [4] = ".";

    step_seq [5] = "s";

    step_seq [6] = ".";

    step_seq [7] = "A#6L";

    step_seq [8] = ".";

    step_seq [9] = "s";

    step_seq [10] = "s";

    step_seq [11] = "C4";

    step_seq [12] = ".";

    step_seq [13] = "S";

    step_seq [14] = "S";

    step_seq [15] = "C3";



    step_seq [16] = "A#5L";

    step_seq [17] = ".";

    step_seq [18] = ".";

    step_seq [19] = "s";

    step_seq [20] = ".";

    step_seq [21] = "s";

    step_seq [22] = ".";

    step_seq [23] = "C3";

    step_seq [24] = ".";

    step_seq [25] = "C3";

    step_seq [26] = "C6";

    step_seq [27] = "s";

    step_seq [28] = "s";

    step_seq [29] = "s";

    step_seq [30] = "s";

    step_seq [31] = "S";


    step_seq_counter = 32;

  }
  
  void ptn_inv02 () {

    step_seq [0] = "S";

    step_seq [1] = ".";

    step_seq [2] = "S";

    step_seq [3] = ".";

    step_seq [4] = "S";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = "S";

    step_seq [8] = "A#8L";

    step_seq [9] = ".";

    step_seq [10] = "C3";

    step_seq [11] = "A8";

    step_seq [12] = ".";

    step_seq [13] = "S";

    step_seq [14] = "S";

    step_seq [15] = "S";


    step_seq_counter = 16;

  }
  
  void ptn_inv03 () {

    step_seq [0] = "S";

    step_seq [1] = "S";

    step_seq [2] = "sL";

    step_seq [3] = ".";

    step_seq [4] = "S";

    step_seq [5] = "S";

    step_seq [6] = "sL";

    step_seq [7] = ".";

    step_seq [8] = "S";

    step_seq [9] = "S";

    step_seq [10] = "sL";

    step_seq [11] = "sL";

    step_seq [12] = "S";

    step_seq [13] = "S";

    step_seq [14] = "sL";

    step_seq [15] = ".";


    step_seq_counter = 16;

  }
  void ptn_inv04 () {

    step_seq [0] = "S";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = "S";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = "S";

    step_seq [7] = ".";

    step_seq [8] = "A#7L";

    step_seq [9] = "S";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = "S";

    step_seq [13] = ".";

    step_seq [14] = "S";

    step_seq [15] = ".";


    step_seq_counter = 16;

  }
  
  void ptn_inv05 () {

    step_seq [0] = "A#6L";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = "S";

    step_seq [4] = "S";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = "s";

    step_seq [8] = "C8";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = "S";

    step_seq [12] = "S";

    step_seq [13] = "s";

    step_seq [14] = "C8";

    step_seq [15] = ".";


    step_seq_counter = 16;

  }
  

  void ptn_01 () {

    step_seq [0] = "C5L";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = ".";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "C5L";

    step_seq [17] = ".";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = ".";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = ".";

    step_seq [31] = ".";

    

    step_seq [32] = "C5L";

    step_seq [33] = ".";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = ".";

    step_seq [38] = ".";

    step_seq [39] = ".";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";



    step_seq [48] = "C5L";

    step_seq [49] = ".";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = ".";

    step_seq [55] = ".";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = ".";

    step_seq [63] = ".";

    step_seq_counter = 64;

  }



  void ptn_02 () {

    step_seq [0] = "C5L";

    step_seq [1] = "C6L";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = ".";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "C5L";

    step_seq [17] = "C6L";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = ".";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = ".";

    step_seq [31] = ".";



    step_seq [32] = "C5L";

    step_seq [33] = "C6L";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = ".";

    step_seq [38] = ".";

    step_seq [39] = ".";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";



    step_seq [48] = "C5L";

    step_seq [49] = "C6L";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = ".";

    step_seq [55] = ".";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = ".";

    step_seq [63] = ".";

    step_seq_counter = 64;

  }



  void ptn_03 () {

    step_seq [0] = "C8";

    step_seq [1] = "C8";

    step_seq [2] = "C8";

    step_seq [3] = "C8";

    step_seq [4] = "C8";

    step_seq [5] = "C8";

    step_seq [6] = "C8";

    step_seq [7] = "C8";

    step_seq [8] = "C8";

    step_seq [9] = "C8";

    step_seq [10] = "C8";

    step_seq [11] = "C8";

    step_seq [12] = "C8";

    step_seq [13] = "C8";

    step_seq [14] = "C8";

    step_seq [15] = "C8";



    step_seq [16] = "C8";

    step_seq [17] = "C8";

    step_seq [18] = "C8";

    step_seq [19] = "C8";

    step_seq [20] = "C8";

    step_seq [21] = "C8";

    step_seq [22] = "C8";

    step_seq [23] = "C8";

    step_seq [24] = "C8";

    step_seq [25] = "C8";

    step_seq [26] = "C8";

    step_seq [27] = "C8";

    step_seq [28] = "C8";

    step_seq [29] = "C8";

    step_seq [30] = "C8";

    step_seq [31] = "C8";



    step_seq [32] = "C8";

    step_seq [33] = "C8";

    step_seq [34] = "C8";

    step_seq [35] = "C8";

    step_seq [36] = "C8";

    step_seq [37] = "C8";

    step_seq [38] = "C8";

    step_seq [39] = "C8";

    step_seq [40] = "C8";

    step_seq [41] = "C8";

    step_seq [42] = "C8";

    step_seq [43] = "C8";

    step_seq [44] = "C8";

    step_seq [45] = "C8";

    step_seq [46] = "C8";

    step_seq [47] = "C8";



    step_seq [48] = "C8";

    step_seq [49] = "C8";

    step_seq [50] = "C8";

    step_seq [51] = "C8";

    step_seq [52] = "C8";

    step_seq [53] = "C8";

    step_seq [54] = "C8";

    step_seq [55] = "C8";

    step_seq [56] = "C8";

    step_seq [57] = "C8";

    step_seq [58] = "C8";

    step_seq [59] = "C8";

    step_seq [60] = "C8";

    step_seq [61] = "C8";

    step_seq [62] = "C8";

    step_seq [63] = "A#7L";

    step_seq_counter = 64;

  }



  void ptn_04 () {

     step_seq [0] = "C8";

    step_seq [1] = "C8";

    step_seq [2] = "C8";

    step_seq [3] = "C8";

    step_seq [4] = "C8";

    step_seq [5] = "C8";

    step_seq [6] = "C8";

    step_seq [7] = "C8";

    step_seq [8] = "C8";

    step_seq [9] = "C8";

    step_seq [10] = "C8";

    step_seq [11] = "C8";

    step_seq [12] = "C8";

    step_seq [13] = "C8";

    step_seq [14] = "C8";

    step_seq [15] = "C8";



    step_seq [16] = "C8";

    step_seq [17] = "C8";

    step_seq [18] = "C8";

    step_seq [19] = "C8";

    step_seq [20] = "C8";

    step_seq [21] = "C8";

    step_seq [22] = "C8";

    step_seq [23] = "C8";

    step_seq [24] = "C8";

    step_seq [25] = "C8";

    step_seq [26] = "C8";

    step_seq [27] = "C8";

    step_seq [28] = "C8";

    step_seq [29] = "C8";

    step_seq [30] = "C8";

    step_seq [31] = "C8";



    step_seq [32] = "C8";

    step_seq [33] = "C#7";

    step_seq [34] = "C8";

    step_seq [35] = "C#7";

    step_seq [36] = "C8";

    step_seq [37] = "C#7";

    step_seq [38] = "C8";

    step_seq [39] = "C#7";

    step_seq [40] = "C8";

    step_seq [41] = "C#7";

    step_seq [42] = "C8";

    step_seq [43] = "C#7";

    step_seq [44] = "C8";

    step_seq [45] = "C#7";

    step_seq [46] = "C8";

    step_seq [47] = "C#7";



    step_seq [48] = "C8";

    step_seq [49] = "C#7";

    step_seq [50] = "C8";

    step_seq [51] = "C#7";

    step_seq [52] = "C8";

    step_seq [53] = "C#7";

    step_seq [54] = "C8";

    step_seq [55] = "C#7";

    step_seq [56] = "C8";

    step_seq [57] = "C#7";

    step_seq [58] = "C8";

    step_seq [59] = "C#7";

    step_seq [60] = "C8";

    step_seq [61] = "C#7";

    step_seq [62] = "C8L";

    step_seq [63] = "C8L";

    step_seq_counter = 64;

  }



  void ptn_05 () {

    step_seq [0] = "C8";

    step_seq [1] = "C8";

    step_seq [2] = "C8";

    step_seq [3] = "C8";

    step_seq [4] = "C8";

    step_seq [5] = "C8";

    step_seq [6] = "C8";

    step_seq [7] = "A#6L";

    step_seq [8] = "C8";

    step_seq [9] = "C8";

    step_seq [10] = "C8";

    step_seq [11] = "C8";

    step_seq [12] = "C8";

    step_seq [13] = "C8";

    step_seq [14] = "C8";

    step_seq [15] = "C8";



    step_seq [16] = "A#5L";

    step_seq [17] = "C8";

    step_seq [18] = "C8";

    step_seq [19] = "C8";

    step_seq [20] = "C8";

    step_seq [21] = "C8";

    step_seq [22] = "C8";

    step_seq [23] = "C8";

    step_seq [24] = "C8";

    step_seq [25] = "C8";

    step_seq [26] = "C8";

    step_seq [27] = "C8";

    step_seq [28] = "C8";

    step_seq [29] = "C8";

    step_seq [30] = "C8";

    step_seq [31] = "C8";



    step_seq [32] = "C8";

    step_seq [33] = "A#7";

    step_seq [34] = "C8";

    step_seq [35] = "A#7";

    step_seq [36] = "C8";

    step_seq [37] = "A#7";

    step_seq [38] = "C8";

    step_seq [39] = "A#7";

    step_seq [40] = "C8";

    step_seq [41] = "A#7";

    step_seq [42] = "C8";

    step_seq [43] = "A#7";

    step_seq [44] = "C8";

    step_seq [45] = "A#7";

    step_seq [46] = "C8";

    step_seq [47] = "A#7";



    step_seq [48] = "C8";

    step_seq [49] = "A#7";

    step_seq [50] = "C8";

    step_seq [51] = "A#7";

    step_seq [52] = "C8";

    step_seq [53] = "A#7";

    step_seq [54] = "C8";

    step_seq [55] = "A#7";

    step_seq [56] = "C8";

    step_seq [57] = "A#7";

    step_seq [58] = "C8";

    step_seq [59] = "A#7";

    step_seq [60] = "C8";

    step_seq [61] = "A#7";

    step_seq [62] = "C8L";

    step_seq [63] = "G#5L";

    step_seq_counter = 64;

  }

  

  void ptn_06 () {

    step_seq [0] = "S";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = "C8";

    step_seq [7] = "A#6L";

    step_seq [8] = "C8";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = "S";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "A#5";

    step_seq [17] = ".";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = "S";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = "C8";

    step_seq [31] = "G#5L";

    

    step_seq [32] = ".";

    step_seq [33] = ".";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = "C8";

    step_seq [38] = "A#6L";

    step_seq [39] = "C8";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = "S";

    step_seq [46] = ".";

    step_seq [47] = ".";

    

    step_seq [48] = "A#5";

    step_seq [49] = ".";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = "S";

    step_seq [55] = "S";

    step_seq [56] = "S";

    step_seq [57] = "C8L";

    step_seq [58] = "S";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = "C8";

    step_seq [63] = "G#5L";

    step_seq_counter = 64;

  }

  

  void ptn_07 () {

    step_seq [0] = ".";

    step_seq [1] = ".";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = "C8";

    step_seq [7] = "A#6L";

    step_seq [8] = "C8";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "A#5";

    step_seq [17] = ".";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = ".";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = "C8";

    step_seq [31] = "G#5L";

    

    step_seq [32] = ".";

    step_seq [33] = ".";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = "C8";

    step_seq [38] = "A#6L";

    step_seq [39] = "C8";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";

    

    step_seq [48] = "A#5";

    step_seq [49] = ".";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = ".";

    step_seq [55] = ".";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = "C8";

    step_seq [63] = "G#5L";

    step_seq_counter = 64;

  }

  

  void ptn_08 () {

    step_seq [0] = "A#5L";

    step_seq [1] = "B5L";

    step_seq [2] = "D#6L";

    step_seq [3] = "A#5L";

    step_seq [4] = "B5L";

    step_seq [5] = "D#6L";

    step_seq [6] = "A#5L";

    step_seq [7] = "B5L";

    step_seq [8] = "D#6L";

    step_seq [9] = "A#5L";

    step_seq [10] = "B5L";

    step_seq [11] = "D#6L";

    step_seq [12] = "A#5L";

    step_seq [13] = "B5L";

    step_seq [14] = "D#6L";

    step_seq [15] = "A#5L";



    step_seq [16] = "B5L";

    step_seq [17] = "D#6L";

    step_seq [18] = "A#5L";

    step_seq [19] = "B5L";

    step_seq [20] = "D#6L";

    step_seq [21] = "A#5L";

    step_seq [22] = "B5L";

    step_seq [23] = "D#6L";

    step_seq [24] = "A#5L";

    step_seq [25] = "B5L";

    step_seq [26] = "D#6L";

    step_seq [27] = "A#5L";

    step_seq [28] = "B5L";

    step_seq [29] = "D#6L";

    step_seq [30] = "A#5L";

    step_seq [31] = "B5L";

    

    step_seq [32] = "D#6L";

    step_seq [33] = "A#5L";

    step_seq [34] = "B5L";

    step_seq [35] = "D#6L";

    step_seq [36] = "A#5L";

    step_seq [37] = "B5L";

    step_seq [38] = "D#6L";

    step_seq [39] = "A#5L";

    step_seq [40] = "B5L";

    step_seq [41] = "D#6L";

    step_seq [42] = "A#5L";

    step_seq [43] = "B5L";

    step_seq [44] = "D#6L";

    step_seq [45] = "A#5L";

    step_seq [46] = "B5L";

    step_seq [47] = "D#6L";

    

    step_seq [48] = "A#5L";

    step_seq [49] = "B5L";

    step_seq [50] = "D#6L";

    step_seq [51] = "A#5L";

    step_seq [52] = "B5L";

    step_seq [53] = "D#6L";

    step_seq [54] = "A#5L";

    step_seq [55] = "B5L";

    step_seq [56] = "D#6L";

    step_seq [57] = "A#5L";

    step_seq [58] = "B5L";

    step_seq [59] = "D#6L";

    step_seq [60] = "A#5L";

    step_seq [61] = "B5L";

    step_seq [62] = "D#6L";

    step_seq [63] = "A#5L";

    step_seq_counter = 64;

  }

  

  void ptn_09 () {

    step_seq [0] = "A#5L";

    step_seq [1] = "B5L";

    step_seq [2] = "D#6L";

    step_seq [3] = "F#6L";

    step_seq [4] = "A#6L";

    step_seq [5] = "C7L";

    step_seq [6] = "A#5L";

    step_seq [7] = "B5L";

    step_seq [8] = "D#6L";

    step_seq [9] = "F#6L";

    step_seq [10] = "A#6L";

    step_seq [11] = "C7L";

    step_seq [12] = "A#5L";

    step_seq [13] = "B5L";

    step_seq [14] = "D#6L";

    step_seq [15] = "F#6L";



    step_seq [16] = "A#6L";

    step_seq [17] = "C7L";

    step_seq [18] = "A#5L";

    step_seq [19] = "B5L";

    step_seq [20] = "D#6L";

    step_seq [21] = "F#6L";

    step_seq [22] = "A#6L";

    step_seq [23] = "C7L";

    step_seq [24] = "A#5L";

    step_seq [25] = "B5L";

    step_seq [26] = "D#6L";

    step_seq [27] = "F#6L";

    step_seq [28] = "A#6L";

    step_seq [29] = "C7L";

    step_seq [30] = "A#5L";

    step_seq [31] = "B5L";

    

    step_seq [32] = "D#6L";

    step_seq [33] = "F#6L";

    step_seq [34] = "A#6L";

    step_seq [35] = "C7L";

    step_seq [36] = "A#5L";

    step_seq [37] = "B5L";

    step_seq [38] = "D#6L";

    step_seq [39] = "F#6L";

    step_seq [40] = "A#6L";

    step_seq [41] = "C7L";

    step_seq [42] = "A#5L";

    step_seq [43] = "B5L";

    step_seq [44] = "D#6L";

    step_seq [45] = "F#6L";

    step_seq [46] = "A#6L";

    step_seq [47] = "C7L";

    

    step_seq [48] = "A#5L";

    step_seq [49] = "B5L";

    step_seq [50] = "D#6L";

    step_seq [51] = "F#6L";

    step_seq [52] = "A#6L";

    step_seq [53] = "C7L";

    step_seq [54] = "A#5L";

    step_seq [55] = "B5L";

    step_seq [56] = "D#6L";

    step_seq [57] = "F#6L";

    step_seq [58] = "A#6L";

    step_seq [59] = "C7L";

    step_seq [60] = "A#5L";

    step_seq [61] = "B5L";

    step_seq [62] = "D#6L";

    step_seq [63] = "F#6L";

    step_seq_counter = 64;

  }

  

  void ptn_10 () {

    step_seq [0] = "s";

    step_seq [1] = "s";

    step_seq [2] = "s";

    step_seq [3] = "s";

    step_seq [4] = "s";

    step_seq [5] = "s";

    step_seq [6] = "s";

    step_seq [7] = "s";

    step_seq [8] = "s";

    step_seq [9] = "s";

    step_seq [10] = "s";

    step_seq [11] = "s";

    step_seq [12] = "s";

    step_seq [13] = "s";

    step_seq [14] = "s";

    step_seq [15] = "s";



    step_seq [16] = "s";

    step_seq [17] = "s";

    step_seq [18] = "s";

    step_seq [19] = "s";

    step_seq [20] = "s";

    step_seq [21] = "s";

    step_seq [22] = "s";

    step_seq [23] = "s";

    step_seq [24] = "s";

    step_seq [25] = "s";

    step_seq [26] = "s";

    step_seq [27] = "s";

    step_seq [28] = "s";

    step_seq [29] = "s";

    step_seq [30] = "s";

    step_seq [31] = "s";

    

    step_seq [32] = "s";

    step_seq [33] = "s";

    step_seq [34] = "s";

    step_seq [35] = "s";

    step_seq [36] = "s";

    step_seq [37] = "s";

    step_seq [38] = "s";

    step_seq [39] = "s";

    step_seq [40] = "s";

    step_seq [41] = "s";

    step_seq [42] = "s";

    step_seq [43] = "s";

    step_seq [44] = "s";

    step_seq [45] = "s";

    step_seq [46] = "s";

    step_seq [47] = "s";

    

    step_seq [48] = "S";

    step_seq [49] = "s";

    step_seq [50] = "S";

    step_seq [51] = "s";

    step_seq [52] = "S";

    step_seq [53] = "s";

    step_seq [54] = "S";

    step_seq [55] = "s";

    step_seq [56] = "S";

    step_seq [57] = "s";

    step_seq [58] = "S";

    step_seq [59] = "s";

    step_seq [60] = "S";

    step_seq [61] = "s";

    step_seq [62] = "S";

    step_seq [63] = "s";

    step_seq_counter = 64;

  }

  

  void ptn_11 () {

    step_seq [0] = "A#5L";

    step_seq [1] = "B5L";

    step_seq [2] = "D#6L";

    step_seq [3] = "F#6L";

    step_seq [4] = "A#6L";

    step_seq [5] = "C7L";

    step_seq [6] = "A#5L";

    step_seq [7] = "B5L";

    step_seq [8] = "D#6L";

    step_seq [9] = "F#6L";

    step_seq [10] = "A#6L";

    step_seq [11] = "C7L";

    step_seq [12] = "A#5L";

    step_seq [13] = "B5L";

    step_seq [14] = "D#6L";

    step_seq [15] = "F#6L";



    step_seq [16] = "A#6L";

    step_seq [17] = "C7L";

    step_seq [18] = "A#5L";

    step_seq [19] = "B5L";

    step_seq [20] = "D#6L";

    step_seq [21] = "F#6L";

    step_seq [22] = "A#6L";

    step_seq [23] = "C7L";

    step_seq [24] = "A#5L";

    step_seq [25] = "B5L";

    step_seq [26] = "D#6L";

    step_seq [27] = "F#6L";

    step_seq [28] = "A#6L";

    step_seq [29] = "C7L";

    step_seq [30] = "A#5L";

    step_seq [31] = "B5L";

    

    step_seq [32] = "D#6L";

    step_seq [33] = "F#6L";

    step_seq [34] = "A#6L";

    step_seq [35] = "C7L";

    step_seq [36] = "A#5L";

    step_seq [37] = "B5L";

    step_seq [38] = "D#6L";

    step_seq [39] = "F#6L";

    step_seq [40] = "A#6L";

    step_seq [41] = "C7L";

    step_seq [42] = "A#5L";

    step_seq [43] = "B5L";

    step_seq [44] = "D#6L";

    step_seq [45] = "F#6L";

    step_seq [46] = "A#6L";

    step_seq [47] = "C7L";

    

    step_seq [48] = "A#5L";

    step_seq [49] = "B5L";

    step_seq [50] = "D#6L";

    step_seq [51] = "F#6L";

    step_seq [52] = "A#6L";

    step_seq [53] = "C7L";

    step_seq [54] = "A#5L";

    step_seq [55] = "B5L";

    step_seq [56] = "D#6L";

    step_seq [57] = "F#6L";

    step_seq [58] = "A#6L";

    step_seq [59] = "C7L";

    step_seq [60] = "A#5L";

    step_seq [61] = "B5L";

    step_seq [62] = "D#6L";

    step_seq [63] = "F#6L";

    step_seq_counter = 64;

  }

  

  void ptn_12 () {

    step_seq [0] = "A#5L";

    step_seq [1] = "B5L";

    step_seq [2] = "D#6L";

    step_seq [3] = "F#6L";

    step_seq [4] = "A#6L";

    step_seq [5] = "C7L";

    step_seq [6] = "A#5L";

    step_seq [7] = "B5L";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "A#6L";

    step_seq [17] = "C7L";

    step_seq [18] = "A#5L";

    step_seq [19] = "B5L";

    step_seq [20] = "D#6L";

    step_seq [21] = "F#6L";

    step_seq [22] = "A#6L";

    step_seq [23] = "C7#";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = ".";

    step_seq [31] = ".";

    

    step_seq [32] = "F#6L";

    step_seq [33] = "D#6L";

    step_seq [34] = "B5LL";

    step_seq [35] = "A#5L";

    step_seq [36] = "C7L";

    step_seq [37] = "A#6L";

    step_seq [38] = "F#6L";

    step_seq [39] = "D#6L";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";

    

    step_seq [48] = "C7L";

    step_seq [49] = "A#6L";

    step_seq [50] = "F#GL";

    step_seq [51] = "D#6L";

    step_seq [52] = "B5L";

    step_seq [53] = "A#5L";

    step_seq [54] = "C7L";

    step_seq [55] = "A#6L";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = ".";

    step_seq [63] = ".";

    step_seq_counter = 64;

  }

  

  void ptn_13 () {

    step_seq [0] = "A#4";

    step_seq [1] = "A#4";

    step_seq [2] = "A#4";

    step_seq [3] = "A#4";

    step_seq [4] = "A#4";

    step_seq [5] = "A#4";

    step_seq [6] = "A#4";

    step_seq [7] = "A#4";

    step_seq [8] = "A#4";

    step_seq [9] = "A#4";

    step_seq [10] = "A#4";

    step_seq [11] = "A#4";

    step_seq [12] = "A#4";

    step_seq [13] = "A#4";

    step_seq [14] = "A#4";

    step_seq [15] = "A#4";



    step_seq [16] = "A#4";

    step_seq [17] = "A#4";

    step_seq [18] = "A#4";

    step_seq [19] = "A#4";

    step_seq [20] = "A#4";

    step_seq [21] = "A#4";

    step_seq [22] = "A#4";

    step_seq [23] = "A#4";

    step_seq [24] = "A#4";

    step_seq [25] = "A#4";

    step_seq [26] = "A#4";

    step_seq [27] = "A#4";

    step_seq [28] = "A#4";

    step_seq [29] = "A#4";

    step_seq [30] = "A#4";

    step_seq [31] = "A#4";

    

    step_seq [32] = "A#4";

    step_seq [33] = "A#4";

    step_seq [34] = "A#4";

    step_seq [35] = "A#4";

    step_seq [36] = "A#4";

    step_seq [37] = "A#4";

    step_seq [38] = "A#4";

    step_seq [39] = "A#4";

    step_seq [40] = "A#4";

    step_seq [41] = "A#4";

    step_seq [42] = "A#4";

    step_seq [43] = "A#4";

    step_seq [44] = "A#4";

    step_seq [45] = "A#4";

    step_seq [46] = "A#4";

    step_seq [47] = "A#4";

    

    step_seq [48] = "A#4";

    step_seq [49] = "A#4";

    step_seq [50] = "A#4";

    step_seq [51] = "A#4";

    step_seq [52] = "A#4";

    step_seq [53] = "A#4";

    step_seq [54] = "A#4";

    step_seq [55] = "A#4";

    step_seq [56] = "A#4";

    step_seq [57] = "A#4";

    step_seq [58] = "A#4";

    step_seq [59] = "A#4";

    step_seq [60] = "A#4";

    step_seq [61] = "A#4";

    step_seq [62] = "A#4";

    step_seq [63] = "A#4";

    step_seq_counter = 64;

  }

  

  void ptn_14 () {

    step_seq [0] = "C5";

    step_seq [1] = "A#4";

    step_seq [2] = "C5";

    step_seq [3] = "A#4";

    step_seq [4] = "C5";

    step_seq [5] = "A#4";

    step_seq [6] = "C5";

    step_seq [7] = "A#4";

    step_seq [8] = "C5";

    step_seq [9] = "A#4";

    step_seq [10] = "C5";

    step_seq [11] = "A#4";

    step_seq [12] = "C5";

    step_seq [13] = "A#4";

    step_seq [14] = "C5";

    step_seq [15] = "A#4";



    step_seq [16] = "G#4";

    step_seq [17] = "A#4";

    step_seq [18] = "G#4";

    step_seq [19] = "A#4";

    step_seq [20] = "G#4";

    step_seq [21] = "A#4";

    step_seq [22] = "G#4";

    step_seq [23] = "A#4";

    step_seq [24] = "G#4";

    step_seq [25] = "A#4";

    step_seq [26] = "G#4";

    step_seq [27] = "A#4";

    step_seq [28] = "G#4";

    step_seq [29] = "A#4";

    step_seq [30] = "G#4";

    step_seq [31] = "A#4";

    

    step_seq [32] = "C5";

    step_seq [33] = "A#4";

    step_seq [34] = "C5";

    step_seq [35] = "A#4";

    step_seq [36] = "C5";

    step_seq [37] = "A#4";

    step_seq [38] = "C5";

    step_seq [39] = "A#4";

    step_seq [40] = "C5";

    step_seq [41] = "A#4";

    step_seq [42] = "C5";

    step_seq [43] = "A#4";

    step_seq [44] = "C5";

    step_seq [45] = "A#4";

    step_seq [46] = "C5";

    step_seq [47] = "A#4";

    

    step_seq [48] = "G#4";

    step_seq [49] = "F#4";

    step_seq [50] = "G#4";

    step_seq [51] = "F#4";

    step_seq [52] = "G#4";

    step_seq [53] = "F#4";

    step_seq [54] = "G#4";

    step_seq [55] = "F#4";

    step_seq [56] = "G#4";

    step_seq [57] = "F#4";

    step_seq [58] = "G#4";

    step_seq [59] = "F#4";

    step_seq [60] = "G#4";

    step_seq [61] = "F#4";

    step_seq [62] = "G#4";

    step_seq [63] = "F#4";

    step_seq_counter = 64;

  }

  

  void ptn_15 () {

    step_seq [0] = "C5L";

    step_seq [1] = "A#4L";

    step_seq [2] = "C5L";

    step_seq [3] = "A#4L";

    step_seq [4] = "C5L";

    step_seq [5] = "A#4L";

    step_seq [6] = "C5L";

    step_seq [7] = "A#4L";

    step_seq [8] = "C5L";

    step_seq [9] = "A#4L";

    step_seq [10] = "C5L";

    step_seq [11] = "A#4L";

    step_seq [12] = "C5L";

    step_seq [13] = "A#4L";

    step_seq [14] = "C5L";

    step_seq [15] = "A#4L";



    step_seq [16] = "G#4L";

    step_seq [17] = "A#4L";

    step_seq [18] = "G#4L";

    step_seq [19] = "A#4L";

    step_seq [20] = "G#4L";

    step_seq [21] = "A#4L";

    step_seq [22] = "A#4L";

    step_seq [23] = "G#4L";

    step_seq [24] = "A#4L";

    step_seq [25] = "G#4L";

    step_seq [26] = "A#4L";

    step_seq [27] = "G#4L";

    step_seq [28] = "A#4L";

    step_seq [29] = "G#4L";

    step_seq [30] = "A#4L";

    step_seq [31] = "G#4L";

    

    step_seq [32] = "C5L";

    step_seq [33] = "A#4L";

    step_seq [34] = "C5L";

    step_seq [35] = "A#4L";

    step_seq [36] = "C5L";

    step_seq [37] = "A#4L";

    step_seq [38] = "C5L";

    step_seq [39] = "A#4L";

    step_seq [40] = "C5L";

    step_seq [41] = "A#4L";

    step_seq [42] = "C5L";

    step_seq [43] = "A#4L";

    step_seq [44] = "C5L";

    step_seq [45] = "A#4L";

    step_seq [46] = "C5L";

    step_seq [47] = "A#4L";

    

    step_seq [48] = "G#4L";

    step_seq [49] = "F#4L";

    step_seq [50] = "G#4L";

    step_seq [51] = "F#4L";

    step_seq [52] = "G#4L";

    step_seq [53] = "F#4L";

    step_seq [54] = "G#4L";

    step_seq [55] = "F#4L";

    step_seq [56] = "G#4L";

    step_seq [57] = "F#4L";

    step_seq [58] = "G#4L";

    step_seq [59] = "F#4L";

    step_seq [60] = "G#4L";

    step_seq [61] = "F#4L";

    step_seq [62] = "G#4L";

    step_seq [63] = "F#4L";

    step_seq_counter = 64;

  }

  

  void ptn_16 () {

    step_seq [0] = "C5L";

    step_seq [1] = "C5L";

    step_seq [2] = "C5L";

    step_seq [3] = "C5L";

    step_seq [4] = "C5L";

    step_seq [5] = "C5L";

    step_seq [6] = "C5L";

    step_seq [7] = "C5L";

    step_seq [8] = "C5L";

    step_seq [9] = "C5L";

    step_seq [10] = "C5L";

    step_seq [11] = "C5L";

    step_seq [12] = "C5L";

    step_seq [13] = "C5L";

    step_seq [14] = "C5L";

    step_seq [15] = "C5L";



    step_seq [16] = "G#4L";

    step_seq [17] = "G#4L";

    step_seq [18] = "G#4L";

    step_seq [19] = "G#4L";

    step_seq [20] = "G#4L";

    step_seq [21] = "G#4L";

    step_seq [22] = "G#4L";

    step_seq [23] = "G#4L";

    step_seq [24] = "G#4L";

    step_seq [25] = "G#4L";

    step_seq [26] = "G#4L";

    step_seq [27] = "G#4L";

    step_seq [28] = "G#4L";

    step_seq [29] = "G#4L";

    step_seq [30] = "G#4L";

    step_seq [31] = "G#4L";

    

    step_seq [32] = "C5L";

    step_seq [33] = "C5L";

    step_seq [34] = "C5L";

    step_seq [35] = "C5L";

    step_seq [36] = "C5L";

    step_seq [37] = "C5L";

    step_seq [38] = "C5L";

    step_seq [39] = "C5L";

    step_seq [40] = "C5L";

    step_seq [41] = "C5L";

    step_seq [42] = "C5L";

    step_seq [43] = "C5L";

    step_seq [44] = "C5L";

    step_seq [45] = "C5L";

    step_seq [46] = "C5L";

    step_seq [47] = "C5L";

    

    step_seq [48] = "G#4L";

    step_seq [49] = "G#4L";

    step_seq [50] = "G#4L";

    step_seq [51] = "G#4L";

    step_seq [52] = "G#4L";

    step_seq [53] = "G#4L";

    step_seq [54] = "G#4L";

    step_seq [55] = "G#4L";

    step_seq [56] = "G#4L";

    step_seq [57] = "G#4L";

    step_seq [58] = "G#4L";

    step_seq [59] = "G#4L";

    step_seq [60] = "G#4L";

    step_seq [61] = "G#4L";

    step_seq [62] = "G#4L";

    step_seq [63] = "G#4L";

    step_seq_counter = 64;

  }

  

  void ptn_17 () {

    step_seq [0] = "C4L";

    step_seq [1] = "C4L";

    step_seq [2] = "C4L";

    step_seq [3] = "C4L";

    step_seq [4] = "C4L";

    step_seq [5] = "C4L";

    step_seq [6] = "C4L";

    step_seq [7] = "C4L";

    step_seq [8] = "C4L";

    step_seq [9] = "C4L";

    step_seq [10] = "C4L";

    step_seq [11] = "C4L";

    step_seq [12] = "C4L";

    step_seq [13] = "C4L";

    step_seq [14] = "C4L";

    step_seq [15] = "C4L";



    step_seq [16] = "G#3L";

    step_seq [17] = "G#3L";

    step_seq [18] = "G#3L";

    step_seq [19] = "G#3L";

    step_seq [20] = "G#3L";

    step_seq [21] = "G#3L";

    step_seq [22] = "G#3L";

    step_seq [23] = "G#3L";

    step_seq [24] = "G#3L";

    step_seq [25] = "G#3L";

    step_seq [26] = "G#3L";

    step_seq [27] = "G#3L";

    step_seq [28] = "G#3L";

    step_seq [29] = "G#3L";

    step_seq [30] = "G#3L";

    step_seq [31] = "G#3L";

    

    step_seq [32] = "C4L";

    step_seq [33] = "C4L";

    step_seq [34] = "C4L";

    step_seq [35] = "C4L";

    step_seq [36] = "C4L";

    step_seq [37] = "C4L";

    step_seq [38] = "C4L";

    step_seq [39] = "C4L";

    step_seq [40] = "C4L";

    step_seq [41] = "C4L";

    step_seq [42] = "C4L";

    step_seq [43] = "C4L";

    step_seq [44] = "C4L";

    step_seq [45] = "C4L";

    step_seq [46] = "C4L";

    step_seq [47] = "C4L";

    

    step_seq [48] = "G#3L";

    step_seq [49] = "G#3L";

    step_seq [50] = "G#3L";

    step_seq [51] = "G#3L";

    step_seq [52] = "G#3L";

    step_seq [53] = "G#3L";

    step_seq [54] = "G#3L";

    step_seq [55] = "G#3L";

    step_seq [56] = "G#3L";

    step_seq [57] = "G#3L";

    step_seq [58] = "G#3L";

    step_seq [59] = "G#3L";

    step_seq [60] = "G#3L";

    step_seq [61] = "G#3L";

    step_seq [62] = "G#3L";

    step_seq [63] = "G#3L";

    step_seq_counter = 64;

  }

  

  void ptn_18 () {

    step_seq [0] = "C7L";

    step_seq [1] = "C6L";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = ".";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = "G#6L";

    step_seq [17] = "G#5L";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = ".";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = ".";

    step_seq [31] = ".";

    

    step_seq [32] = "C7L";

    step_seq [33] = "C6L";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = ".";

    step_seq [38] = ".";

    step_seq [39] = ".";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";

    

    step_seq [48] = "G#6L";

    step_seq [49] = "G#5L";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = ".";

    step_seq [55] = ".";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = ".";

    step_seq [63] = ".";

    step_seq_counter = 64;

  }

  

  void ptn_19 () {

    step_seq [0] = "C7L";

    step_seq [1] = "C6L";

    step_seq [2] = ".";

    step_seq [3] = ".";

    step_seq [4] = ".";

    step_seq [5] = ".";

    step_seq [6] = ".";

    step_seq [7] = ".";

    step_seq [8] = ".";

    step_seq [9] = ".";

    step_seq [10] = ".";

    step_seq [11] = ".";

    step_seq [12] = ".";

    step_seq [13] = ".";

    step_seq [14] = ".";

    step_seq [15] = ".";



    step_seq [16] = ".";

    step_seq [17] = ".";

    step_seq [18] = ".";

    step_seq [19] = ".";

    step_seq [20] = ".";

    step_seq [21] = ".";

    step_seq [22] = ".";

    step_seq [23] = ".";

    step_seq [24] = ".";

    step_seq [25] = ".";

    step_seq [26] = ".";

    step_seq [27] = ".";

    step_seq [28] = ".";

    step_seq [29] = ".";

    step_seq [30] = ".";

    step_seq [31] = ".";

    

    step_seq [32] = "C7L";

    step_seq [33] = "C6L";

    step_seq [34] = ".";

    step_seq [35] = ".";

    step_seq [36] = ".";

    step_seq [37] = ".";

    step_seq [38] = ".";

    step_seq [39] = ".";

    step_seq [40] = ".";

    step_seq [41] = ".";

    step_seq [42] = ".";

    step_seq [43] = ".";

    step_seq [44] = ".";

    step_seq [45] = ".";

    step_seq [46] = ".";

    step_seq [47] = ".";

    

    step_seq [48] = ".";

    step_seq [49] = ".";

    step_seq [50] = ".";

    step_seq [51] = ".";

    step_seq [52] = ".";

    step_seq [53] = ".";

    step_seq [54] = ".";

    step_seq [55] = ".";

    step_seq [56] = ".";

    step_seq [57] = ".";

    step_seq [58] = ".";

    step_seq [59] = ".";

    step_seq [60] = ".";

    step_seq [61] = ".";

    step_seq [62] = ".";

    step_seq [63] = ".";

    step_seq_counter = 64;

  }
  
  
  //************************************************
  ///////////////////////////////////////////////////

  void listSeqSteps () {
#ifdef DEBUG
    Serial.println ();
    Serial.println ("Seq steps");
    for (i=0; i<step_seq_counter; i++) {
      char * s;

      //Serial.print (step_seq [step_seq_counter]);
      s = step_seq [i];

      Serial.print (i);
      Serial.print (" ");
      Serial.print (s);
      Serial.println ();
    }
#endif
  }


  boolean complete;
  boolean e_ready;
  int i;  
  int j;



  int bpm;

  boolean running;

  char * step_seq [64];

  int step_seq_counter;

  int beat;

  int pattern_length;

  long time_keeper;
  long velocity_keeper;
  long velocity_counter;

  int short_velocity;
  int long_velocity;

  boolean triggered;


  long click_4;
  long click_8;
  long click_16;


};

