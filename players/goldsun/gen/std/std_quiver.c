/*  standard quiver. Goldsun 130295
    usable for bows that inherit : /p/g/gen/std/std_bow
 
Functions for you:
 
 set_amount(i)  -set amount of arrows in the quiver
 set_name(str)  -name of quiver (alt_name and alias_name are set to
	          alt_name.. NEVER change this string !!!
                  alias_name = "quiver"

Example : 

    inherit "/players/goldsun/gen/std/std_quiver";
     
     void reset(int arg){
      if (!arg){        / call ::reset() after your definitions /
        set_name("goldsun's quiver");
        set_amount(300);
      }
      ::reset(arg);
    }
*/

inherit "/obj/treasure";
int amount, Max;


void set_amount(int how){ Max=how; amount=how; }

string size(int num){
 switch(num){
  case 0..199     : return "small";
  case 200..999   : return "medium";
  case 1000..1999 : return "large";
  default : return "x-large";
 }
}

void reset(int arg){

if (arg) return;
 set_alias("quiver");
 set_alt_name("quiver_of_arrows");
 set_name("quiver of arrows");
 set_short("A leather quiver of arrows ["+size(Max)+"]");
 set_weight(1);
}

int query_value(){ return( amount ); }

/* dec_arrows(i)
This function is uses for shooting arrow from quiver.
It is used by bow.
*/

void dec_arrows(int how_many){   
 amount-=how_many;
 if (amount<1){
    write("The quiver is empty. You destruct it.\n");
    destruct(this_object());
  }
}

 long(){
  string ho;
  int i;

  i=amount/Max;
  if (i = 1) ho="It is full.";
  else if (i > 0.8) ho="It is full.";
  else if (i > 0.6) ho="It is almost full.";
  else if (i > 0.4) ho="It is half full.";
  else if (i > 0.3) ho="There are still some arrows in it.";
  else if (i > 0.2) ho="It is almost empty.";
  else if (i > 0.1) ho="There are still a few arrows in it.";
  else ho="It will be empty very soon.\n"+
      "You should buy new one as soon as possible.";
  write("A leather quiver. "+ho+"\n");
  }
