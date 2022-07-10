//just use an unordered map to store the frequencies of all the elements and then if
// frequency>0 then print the element and its frequency.

unordered_map <char,int> ump;
for(int i=0; i<s.size(); i++)
{
	ump[s[i]]++;
}
for(auto it = ump.begin(); it != ump.end(); it++)
{
	if(it->second > 1)
		cout<<it->first<<" "<<it->second<<"\n";
}