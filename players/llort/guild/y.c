#define SM		"obj/skill_master"

string know_level(int val)
{
   string rtc;

   if(val ==   0)      rtc = "not learned";
   else if(val <   10) rtc = "Awful";
   else if(val <   25) rtc = "Bad";
   else if(val <   40) rtc = "Poor";
   else if(val <   60) rtc = "Average";
   else if(val <   80) rtc = "Fine";
   else if(val <   90) rtc = "Good";
   else if(val <   95) rtc = "Very good";
   else if(val <  100) rtc = "Superb";
   else if(val == 100) rtc = "Perfect";
   else                rtc = " ** Strange ** ";

   return rtc;
}

string time_level(int val)
{
   string rtc;

   if(val <  -2) rtc = " ** Strange ** ";
   else if(val == -2) rtc = "-----";
   else if(val == -1) rtc = "Immediate";
   else if(val ==  0) rtc = "Very short";
   else if(val ==  1) rtc = "Short";
   else if(val ==  2) rtc = "Average";
   else if(val ==  3) rtc = "Long";
   else if(val ==  4) rtc = "Very long";
   else rtc = "Extremly long";

   return rtc;
}
