string know_level(int val)
{
   string rtc;

   if(val ==   0)      rtc = "None";
   else if(val <   10) rtc = "Awful";
   else if(val <   25) rtc = "Bad";
   else if(val <   40) rtc = "Poor";
   else if(val <   60) rtc = "Average";
   else if(val <   80) rtc = "Fine";
   else if(val <   90) rtc = "Good";
   else if(val <   95) rtc = "Vy good";
   else if(val <  100) rtc = "Superb";
   else if(val == 100) rtc = "Perfect";
   else                rtc = "Strange";

   return rtc;
}
