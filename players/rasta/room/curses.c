/* curses */
int time, start, curse;
string extra_str, last_cmd;
id(str)
{
        return str=="curses";
}
reset(arg)
{
        if (arg)
        {
                if (!environment(this_object()))
                {
                        destruct(this_object());
                        return;
                }
                if (!living(environment(this_object())))
                {
                        destruct(this_object());
                        return;
                }
                return;
        }
        time=(random(4)+1)*60;
}
init()
{
        if (this_player()!=environment(this_object()))
                return;
        log_file("jus_curse",capitalize(this_player()->query_real_name())+"\n");
        if (curse==0)
        {
                add_action("filter", "", 1);
                extra_str = "And is blissfully asleep.";
                write ("A staff taps three times.  You feel tired and lie down for a rest.\n");
        }
        if (curse==1)
        {
                add_action("said","",1);
                extra_str="And looks confused";
                write ("You suddenly feel dis-oriented.\n");
        }
        start=time();
}
filter(str)
{
        if (query_verb()=="snore" || query_verb()=="fart" || query_verb()=="yawn" || query_verb()=="stretch")
                return;
        if (query_verb()=="quit")
                return;
        if (query_verb()=="help" && this_player()->query_level()>19)
                destruct(this_object());
        else
                write("What, in your sleep?\n");
        if (time()>start+time)
                destruct(this_object());
        return 1;
}
said(str)
{
        string temp, tmp;
        int a, b, c;
        object com;
        if (time()>start+time)
           {
                destruct(this_object());
                return;
        }
        tmp="";
        if (!query_verb())
                return;
        if (query_verb()=="help" && this_player()->query_level()>19)
        {
                destruct(this_object());
                return 1;
        }
        if (!str)
                return;
        temp=explode(str," ");
        if (sizeof(temp)<2)
        return;
        if (last_cmd==query_verb())
        {                
                last_cmd="";
                return;
        }
        last_cmd=query_verb();
        if (query_verb()=="tell")
        {
                tmp=temp[0]+" ";
                temp[0]="";
        }
        do
        {
                a=random(sizeof(temp));
                if (temp[a]!="")
                   {
                        if (c)
                                tmp=tmp+" ";
                        tmp=tmp+temp[a];
                        temp[a]="";
                }
                else
                        a=0;
                c=0;
                for (b=0;b<sizeof(temp);b++)
                {
                        if(!c)
                        c=temp[b]!="";
                }
        }
        while(c);
        tmp=query_verb()+" "+tmp;
        command(tmp,environment(this_object()));
        return 1;
}
extra_look()
{
        return extra_str;
}
set_curse(arg)
{
        curse=arg;
        log_file("jus_curse",capitalize(this_player()->query_real_name())+" used curse "+query_verb()+" on ");
        return 1;
}
