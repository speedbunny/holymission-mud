inherit "/obj/thing";

void  reset(int arg){
  ::reset(arg);
 if (arg) return;
 set_name("scroll");
 set_alias("goldsun_scroll_for_hook");
 set_short("A scroll");
 set_long("A scroll.\n");
 }

init(){
 ::init();
add_action("read","read");
}

int read(string str){
 if (str=="scroll"){
   write("There is written:\n");
   write("Ako chytit zlatu rybu:\n"+
         "Zober cln a velku siet a chod na more o polnoci za splnu mesiaca.\n"+
         "Tam hod siet do mora. Cakaj 20 minut a vytiahni ju. Ak je plna,\n"+
         "tak mas smolu a skus to o mesiac, ale ak je prazdna, tak you hod\n"+
         "este raz. Toto opakuj 2 krat. na tretie hodenie by mala zlata ryba\n"+
         "byt v sieti.\nAle aj tak je to blbost, haha.\n\n     Merlin. \n"); 
  return 1;
  }
}  
