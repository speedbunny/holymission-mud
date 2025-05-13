// who() rewritten moonie 190893

#define FILTER(x) u=filter_array(users(),x,this_object()); break;

int who(string arg) {

    object *u;
    int i,j,l,hlp;
    string level,s;

    if(!arg)
        u=users();
    else {
        switch(arg) {
            case "mortal":
                FILTER("_mortal");
                break;
            case "immortal":
                FILTER("_immortal");
                break;
            case "male":
                FILTER("_male");
                break;
            case "female":
                FILTER("_female");
                break;
            case "legendary":
                FILTER("_legendary");
                break;
            case "arena":
                FILTER("_arena");
                break;
            default:
                write("Usage: who \
[mortal/immortal/male/female/legendary/arena]\n");
                return 1;
                break;
        }
        if(!sizeof(u)) {
            printf("No %s players on Holy Mission currently.\n",arg);
            return 1;
        }
        printf("%s players on Holy Mission:\n\n",capitalize(arg));
    }

        write("=================================================================\
=============\n");

    u=sort_array(u,"whosort",this_object());
    j=sizeof(u);

    for(i=0;i<j;i++) {
        l=(int)u[i]->query_level();

        switch(l) {
            case -1..29:
                hlp=l+u[i]->query_legend_level();
                if(hlp>29) {
                    level=(this_player()->query_immortal()?
                          (u[i]->query_testchar()?
                          (u[i]->query_legend_level()>9?
                          sprintf("  [T %2d]",u[i]->query_legend_level()):
                          sprintf("  [T 0%d]",u[i]->query_legend_level())):
                          (u[i]->query_legend_level()>9?
                          sprintf("  [L %2d]",u[i]->query_legend_level()):
                          sprintf("  [L 0%d]",u[i]->query_legend_level()))):
                          "[Legend]");
                }
                else {
                    level=(this_player()->query_immortal()?
                          (u[i]->query_testchar()?
                          (l>9?
                          sprintf("  [T %2d]",l):
                          sprintf("  [T 0%d]",l)):
                          (l>9?
                          sprintf("  [P %2d]",l):
                          sprintf("  [P 0%d]",l))):
                          "[Player]");
                }
                break;
            case 30..32:
                level="[NewWiz]";
                break;
            case 33..35:
                level="[Wizard]";
                break;
            case 36..39:
                level="[Sage]";
                break;
            case 40..49:
                level="[ElderWiz]";
                break;
            case 1000:
               level="[God]";
               break;
            default:
                level="[ArchWiz]";
                break;
        }

        if(!(s=(string)u[i]->query_presentation(0)))
            s=capitalize((string)u[i]->query_real_name());
        printf("%10=s %-68=s\n",level,s);
    }

    printf("============================== %i players online ===========\
===================\n",j);
    return 1;
}

status _mortal(object ob)    { return (int)ob->query_level()<30;  }
status _immortal(object ob)  { return (int)ob->query_level()>29;  }
status _male(object ob)      { return (int)ob->query_gender()==1; }
status _female(object ob)    { return (int)ob->query_gender()==2; }
status _legendary(object ob) { return (int)(ob->query_legend_level() > 0); }
status _arena(object ob) { 
   return ((int)(environment(ob) && environment(ob)->query_arena()) );
}

status whosort(object p1, object p2) { 
    int l1,l2;

    l1=p1->query_level();
    l2=p2->query_level();

    if(p1->query_immortal())
        l1+=100;
    else
        l1+=p1->query_legend_level();

    if(p2->query_immortal())
        l2+=100;
    else
        l2 += p2->query_legend_level();

    return(l1<l2);
}