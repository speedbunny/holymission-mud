// Setgdrank: Coded by Tinman
int do_setgdrank(int arg) {
        int buf;
	string who;

        if(this_player()->query_real_name() != "nae" &&
        this_player()->query_real_name() != "tinman")
        {
         write("What?\n");
        return 1;
        }

        if(!arg) {
        write("Syntax Setgdrank <level>\n");
        write("0                Member\n");
        write("10               Assistant TimeLord\n");
        write("20               TimeLord\n");
        write("50               Assistant Guild Master\n");
        write("100              GM in training\n");
        write("150              Guild Master\n");
       write("200              Retired Guild Master\n");
        return 1;
        }

        if(sscanf(arg,"%s",who) == 1)
        buf = -1;
	sscanf(arg,"%s %d",who,buf);

        if(!find_player(who)) {
        write("Can't find that player.\n");
        return 1;
        }

        if(buf == -1) {
        write("What rank do you want to set it to?\n");
        return 1;
        }

        if(buf < 0) {
        write("You can't set a negative rank!\n");
        return 1;
        }

       (present("vagsoul", find_player(who)))->set_gld_status(buf);
        write("Ok\n");
        return 1;
}
