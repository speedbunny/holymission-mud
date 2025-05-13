inherit "/obj/monster";

reset(arg) {
   object pot;
   int    i;

   ::reset(arg);
   if (arg)
      return;
   set_race("dragon");
   set_name("copper dragon");
   set_alt_name( "dragon" );
   set_level(55);
   set_size(5);
   set_short("a copper dragon");
   set_long( "								   \n"+
"									   \n"+
"                                            ______,----'~~~~~~~~~`-----.__\n"+
"                                    .  .    `//====-_             ___,-' `\n"+
"                    -.            \_|// .   /||\\  `~~~~`---.___./        \n"+
"              ______-==.       _-~o~  \/    |||  \\           _,'`        \n"+
"        __,--'   ,=='||\=_    /_--~/_-'|-   |`\   \\        ,'            \n"+
"     _-'      ,='    |  \\`.   '-'~7  /-   /  ||   `\.     /              \n"+
"   .'       ,'       |   \\ \_    /  /-   /   ||      \   /               \n"+
"  / _____  /         |     \\.`-_/  /|- _/   ,||       \ /                \n"+
" ,-'     `-|--'~~`--_ \     `==-/  `| \'--===-'       _/`                 \n"+
"           '         `-|      /|    )-'\~'      _,--~'                    \n"+
"                       '-~~\_/ |    |   `\_   ,~             /\           \n"+
"                            /  \     \__   \/~               `\__         \n"+
"                        _,-' _/'\ ,-'~____-'`-/                 ``===\    \n"+
"                       ((->/'    \|||' `.     ~`-/ ,                _||   \n"+
"                                  \_     ~\      `^---|__i__i__\--~'_/    \n"+
"                                 __-^-_    `)  \-.______________,-~'      \n"+
"                                //,-'~~`__--^-  |-------~~~~~'            \n"+
"                                       //,--~~`-\                         \n"+
"                                                                          \n");
   set_gender(1);
   set_al(1000);
   set_wc(20);
   set_n_ac(45);
   set_number_of_arms(2);      
   set_language_skill(2,100);
   change_spell( "magic missile", 99, 95, 0 );
   change_spell( "fireball", 99, 95, 0 );
   change_spell( "lightning bolt", 99, 95, 1 );
}

int concentrate( object vic ) {
   int rnd;

   if ( vic && !query_concentrating() ) { 
      rnd = random( 100 );
      if ( rnd <= 20 )                              
         npc_process_spell( "magic missile", vic->query_real_name() );
      else if ( rnd < 80 )                         
         npc_process_spell( "fireball", vic->query_real_name() );
      else if ( rnd >= 95)                                       
         npc_process_spell( "lightning bolt", vic->query_real_name() );
      else           
         return(0);
		return(1);
   }
   return(0);
}
