inherit "/obj/thing";

reset ( tick )
{
    ::reset( tick );
    if( tick ) return;

    set_name("scroll");
    set_alt_name("wish");
    set_alias("scroll of wish");
    set_short("Scroll of wish");
    set_long("This seems to be a wish scroll, one of the rarest items you've\n"+
             "ever seen. It humms powerfully.\n");
    set_value(1);
    set_weight(0);
}

init()
{
    ::init();

    add_action("recite","recite");
}

recite(arg)
{
    string id_str, effect, txt;
    int i;

    if(!arg) return;
    if(sscanf(arg,"%s %s",id_str,effect) != 2) return;
    if(!id(id_str)) return;
    say(this_player()->query_name()+" recites a scroll and it vanishes.\n");
    switch(effect)
    {
        case "experience":
            i=50000+random(100000);
            this_player()->add_experience(i);
            write("You wish for experience."+
                  " You receife "+i+" experience points.\n");
            break;
        case "gold":
            i=this_player()->query_level()*2500-this_player()->query_money();
            this_player()->add_money(i);
            write("You wish for gold."+
                  " You receife "+i+" gold coins.\n");
            break;
        case "str":
            i=this_player()->query_r_stats(0);
            write("You wish for strength. ");
            if(i > 39) 
            {
                write("You are already at the maximum strength.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_str(i+1);
                write("You become stronger!\n");
            }
            break;
        case "dex":
            i=this_player()->query_r_stats(1);
            write("You wish for dexterity. ");
            if(i > 39) 
            {
                write("You are already at the maximum dexterity.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_dex(i+1);
                write("You become more dexterious!\n");
            }
            break;
        case "con":
            i=this_player()->query_r_stats(2);
            write("You wish for constitution. ");
            if(i > 39) 
            {
                write("You are already at the maximum constitution.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_con(i+1);
                write("You become healthier!\n");
            }
            break;
        case "int":
            i=this_player()->query_r_stats(3);
            write("You wish for inteligence. ");
            if(i > 39) 
            {
                write("You are already at the maximum inteligence.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_int(i+1);
                write("You become smarter!\n");
            }
            break;
        case "chr":
            i=this_player()->query_r_stats(5);
            write("You wish for charisma. ");
            if(i > 39) 
            {
                write("You are already at the maximum charisma.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_chr(i+1);
                write("You become more handsome!\n");
            }
            break;
        case "wis":
            i=this_player()->query_r_stats(4);
            write("You wish for wisdom. ");
            if(i > 39) 
            {
                write("You are already at the maximum wisdom.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
            }
            else
            {
                this_player()->set_wis(i+1);
                write("You become wiser!\n");
            }
            break;
        case "recall":
            write("You wish to be teleported to the church.\n");
            write("You are teleported somewhere!\n");
            this_player()->move_player("X#room/church");
            break;
        case "power":
            txt = read_file("/players/llort/secure/wishes/"+
                  this_player()->query_real_name()+"_power");
            i = to_int(txt);
            write("You wish for battelforce.\n");
            if(i==20)
            {
                write("You are already at the maximum power.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
                break;
            }
            write("Your hands become lethal weapons!\n");
            i += ((21 - i) / 2);
            this_player()->set_n_wc(i);
            this_player()->set_number_of_arms(2);
            rm("/players/llort/secure/wishes/"+
               this_player()->query_real_name()+"_power");
            write_file("/players/llort/secure/wishes/"+
                       this_player()->query_real_name()+"_power",""+i);
            break;
        case "defense":
            txt = read_file("/players/llort/secure/wishes/"+
                  this_player()->query_real_name()+"_defense");
            i = to_int(txt);
            write("You wish for protection.\n");
            if(i==15)
            {
                write("You are already at the maximum protection.\n"+
                      "The gods are angry about you!\n");
                this_player()->hit_player(500,7);
                break;
            }
            write("You skin seems to harden!\n");
            i += ((16-i)/2);
            this_player()->set_n_ac(i);
            rm("/players/llort/secure/wishes/"+
               this_player()->query_real_name()+"_defense");
            write_file("/players/llort/secure/wishes/"+
                       this_player()->query_real_name()+"_defense",""+i);
            break;
        default:
            write("The gods are angry about you!\n");
            this_player()->hit_player(500,7);
    }
    log_file("wish",this_player()->query_real_name()+" wished for "+
             effect+" at "+ctime(time())+"\n");
    write("The scroll vanishes!\n");
    destruct(this_object());
    return 1;
}
