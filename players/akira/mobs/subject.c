inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("Test Subject");
set_long("This is one of the test subject the students use to test there\n"+
         "mental skills on. You can tell that something has been done to\n"+
         "the test subjects voice, because he is unable to speak or to\n"+
         "cry out. You can tell by the look in his eyes that he will\n"+
         "welcome death when it comes for him.\n");
set_alias("subject");
set_level(2+random(2));
set_al(500);
set_ac(5);
set_wc(5);
set_number_of_arms(2);
}
