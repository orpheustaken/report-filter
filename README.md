### A simple solution for a minor inconvenience

Reasons aside, the purpose of this program is to remove the date and .json extension from a database query and leave only the eight number sequence in the middle.

The `generatelist.c` program inside `report_list/` will create a sample file with the same format as a real one:

```bash
$ ./generatelist 10 # quantity as argument
$ cat report_list

./YYYY-MM-DD/68785923.json
./YYYY-MM-DD/07926016.json
./YYYY-MM-DD/19111857.json
./YYYY-MM-DD/49431668.json
./YYYY-MM-DD/64825075.json
./YYYY-MM-DD/77769820.json
./YYYY-MM-DD/93212708.json
./YYYY-MM-DD/87395092.json
./YYYY-MM-DD/67410387.json
./YYYY-MM-DD/25516825.json
```
And finally, `reportfilter.c` will do its job:

```bash
$ ./reportfilter report_list/report_list
$ cat report_result

68785923
07926016
19111857
49431668
64825075
77769820
93212708
87395092
67410387
25516825
```
