
#define AA      add_action
#define TO      this_object()
#define TP      this_player()
#define FP      find_player
#define RNAME   query_real_name()
#define CAP     capitalize

inherit "obj/weapon";

reset() {
    ::reset();
    
    set_id( "wand" );
    set_short( "An small emerald wand" );
    set_long( "This is a dark, green emerald wand. \n" +
      "Type 'cmds' for commands.\n" );
    set_class( 20 );
}

get() { return 1; }
drop() { return 1; }

init() {
    ::init();
    
    AA( "info", "info" );
    AA( "cmd", "cmds" );

        if( TP->RNAME != "airborne" ) {
           write( "This is a private tool that you are not supposed to have!\n" );
           write( "Enjoy re-logging in! I hope you have learned your lesson.\n" );
           destruct( TO );
        }
    
}

cmd() {
    write(
      "\n"+
      "|================================================================| \n"+
      "| The wand gives you the following commands:                     | \n"+
      "|                                                                | \n"+
      "| Command             Its function                               | \n"+
      "|================================================================| \n"+
      "| info [living]     : Shows the name / level / path in / and     | \n"+
      "|                     where they are.                            | \n"+
      "| cmds              : Shows this screen =]                       | \n"+            
      "|================================================================| \n"+
      "\n");
    
    return 1;
}

what_guild( object ob ) {
   switch( ob->query_guild() ) {
        case 0:  return "[Adventures]                              |"; break;
        case 1:  return "[Thief]                                   |"; break;
        case 2:  return "[Druid]                                   |"; break;
        case 3:  return "[Fighter]                                 |"; break;
        case 4:  return "[Jedi]                                    |"; break;
        case 5:  return "[Mage]                                    |"; break;
        case 6:  return "[Bard]                                    |"; break;
        case 7:  return "[Monk]                                    |"; break;
        case 8:  return "[Ninja]                                   |"; break;
        case 9:  return "[Summoner]                                |"; break;
        case 10: return "[Vagabond]                               |"; break;
        case 11: return "[Barbarian]                              |"; break;
        default: return "[Bugged!]                                 |"; break;
   }
}

what_level( object ob ) {
   switch( ob->query_level() ) {
        case 1000: return "[God]                                   |";
                break;
        case 250..350:  return "[Arch]                                  |";
                break;
        case 200:  return "[Elder]                                 |";
                break;
        case 180:  return "[Retired]                               |";
                break;
        case 160:  return "[Sage]                                  |";
                break;
        case 140:  return "[Wizard]                                |";
                break;
        case 120:  return "[New Wizard]                            |";
                break;
        case 100:  return "[Apprentice Wizard]                     |";
                break;
        default:   return "[Player]                                 |";
                break;
   }
}

what_legend_level( object ob ) {
   switch( ob->query_legend_level() ) {
        case 1..9:   return "                                           |";
                break;
        case 10..20: return "                                          |";
                break;
        default: return "                                           |";
                break;
   }
}

what_age( object ob ) {
   switch( ob->query_age() / 43200 ) {
        case 1..9:     return "                                    |";
                break;
        case 10..99:   return "                                   |";
                break;
        case 100..999: return "                                  |";
                break;
        default:       return "                                    |";
                break;                              
   }
}

what_idle( object ob ) {
   switch( ob->query_idle() / 60 ) {
        case 1..9:     return "                                |";
                break;                                          
        case 10..99:   return "                               |";
                break;
        case 100..999: return "                              |";
                break;
        default:       return "                                |";
   }
}

info( string str ) {
    object target;
    
    if( !FP( str ) ) {
        write( "That player is not logged in!\n" );
        return 1;
    }
    
    target = FP( str );
    
    write(process_string(
        "|==============================================================| \n" +
        "| INFORMATION ---> PLAYER / WIZARD                             | \n" +
        "|==============================================================| \n" +
        "| NAME           : " + CAP( target->RNAME ) + "\n" +
        "|                                                              | \n" +
        "| GUILD          : " + target->query_guild() + " " +
				what_guild( target ) + "\n" +
        "|                                                              | \n" +
        "| LEVEL          : " + target->query_level() + " " +
                                what_level( target ) + "\n" +
        "| LEGEND LEVEL   : " + target->query_legend_level() +
                                what_legend_level( target ) + "\n" +
        "| EXPERIENCE     : " + target->query_exp() + "\n" +
        "| AGE            : ~ " + target->query_age() / 43200 + " days" +
                                what_age( target ) + "\n" +
        "|                                                              | \n" +
        "| LOGGED IN FROM : " + query_ip_name(target) + "\n" +
        "| IDLE           : ~ " + query_idle(target) / 60 + " minutes " +
                                what_idle( target ) + "\n" +
        "|                                                              | \n" +
        "| PATH           : /" + target->query_path() + "/\n" +
        "| LOCATION       : /" + file_name( environment(target) ) +".c\n" +
        "|==============================================================| \n"));
    
    return 1;
}

/*
query_auto_load() {
    return "/players/apollo/private/stuff/info:";
}
*/

