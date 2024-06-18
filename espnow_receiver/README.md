# Log record
To generate logs.

### To flash: ### 
Enter the command:
  get_idf && idf.py -p /dev/ttyACM0 flash

#### To monitor: ####

To generate log, run:
  get_idf && idf.py -p /dev/ttyACM0 monitor | tee debug/data.log



