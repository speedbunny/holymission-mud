track(string str) {
        object tracked;
        if(!str) {
                notify_fail("What do you wish to track?\n");
                return 0;
        }
        tracked=find_living(lower_case(str));
        if(!tracked) {
	 notify_fail("You cannot track the smell of that creature.\n");
	 return 0;
        }
	if(!environment(tracked) || environment(tracked)->short()=="It's pitch dark" || !environment(tracked)->query_long())
	 write("You can track down the smell of the creature but cannot picture its location in your mind.\n");
	else
         write("You manage to track the smell of that creature and you locate it in a place with this description:\n"+environment(tracked)->query_long());
        return 1;
}
