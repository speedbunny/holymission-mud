inherit "/obj/thing";

#define COMS ({"say","ninja","tell","ring","help","who","score","look",\
               "rwhere","alias","ering","i","l","exa","sc","chat",\
               "smile","finger"})

#define INT_FAC  9
#define WIS_FAC  9
#define CHR_FAC  12
#define LVL_FAC  9

#define TP environment()

#define FORM (TP->query_int()/INT_FAC) + (TP->query_wis()/WIS_FAC) \
             + (TP->query_chr()/CHR_FAC) + (TP->query_level()/LVL_FAC)
               
#define RATE (3 + (2*(FORM)))

int heal;

void reset(int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("clean_blocker");
        set_weight(0);
        set_value(0);
        enable_commands();
    }
}

string short()
{
    return "";
}

void init() 
{
    object tp;
    
    if (tp=this_player())
        tp->set_meditating();
    add_action("check_allowed","",1);
    set_heart_beat(1);
}

status is_player_to_tell(object ob,object tp)
{
    return (call_other(ob,"query_player") && (ob != tp));
}

void remove_me()
{
    object tp;

    if ((tp=environment()) && call_other(tp,"query_player"))
    {
        tell_object(tp, "You stop meditating.\n");
        say(capitalize(tp->query_name()) +
          " stops meditating.\n");
    }
    destruct(this_object());
}

int check_allowed(string arg) 
{ 
    if (objectp(environment()) && environment()!=this_player())
        return 0;
    else if (query_verb() == "wake" || query_verb() == "wakeup")
    {
        remove_me();
        return 1;
    }
    else if (this_player()->query_immortal() 
       || member_array(query_verb(),COMS)!=-1)
        return 0;
    tell_object(TP,"You can't do that while meditating, type 'wakeup' to "+
      "stop.\n");
    return 1;
}

void heart_beat()
{
    object ob;
    object tp;

    if ( objectp(environment()) && living(tp = environment()) )
    {
        ob = environment()->query_attack();

        if((tp->query_hp() >= tp->query_max_hp()) &&
        (tp->query_sp() >= tp->query_max_sp())) 
            command("wakeup",tp);
        else if (ob && environment(tp)==environment(ob) )
            command("wakeup",tp);
        else 
        {
            if (!heal)
                heal = 1;
            if(random(50) < heal);
                call_other(tp,"heal_self",RATE);
        tp->heal_self(random(5));
        }
    }
    else 
        remove_me();
}

int add_heal(int h)
{
   heal = h;
}

