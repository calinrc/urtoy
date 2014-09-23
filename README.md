urtoy
=====

Description:
------------

URToy cpp project want to be the server side of an universal IR remote control tool.
The initial version will use the usb IRToy device to record, and resend remotes commands previously recorded by the same device 

Version
-----------

0.0.1  


Notes:
-----

The project is in early stage of it, in the sense that can not be use it at all at this time.


Communication protocol details:

 - Command IDs, remoteIds and remote commandIds  - are one byte value
 - int values are sent as 32 bits big endien values
 - server status value - one byte value 
 - String representation - 32 bits int length value + UTF-8 bytes

Commands:
---------


### Login 
		* Client - Sends command id + protocol identifier ("urtoy" 5 bytes chars) + 2 bytes protocol version (minor , major)
		* Server - Server Sends status + Nonce (String value no more than 20 chars  )
		* Client - Response UTF-8 string  ---- (username + ':' +string( (int) charCount(password+nonce))  - This might be replaced with md5 in the future 
		* Server - Response status ok or close connection (one bytes)

### Logout
		* Client sends command id
		* Server close connection

### GetRemotes
		* Client sends command id
		* Server sends back status + byte list length + List of pairs (byte - remoteId , String remoteName )

### SendRemoteCommand
		* Client sends command id + remoteId (byte) + remote commandID (byte)
		* Server respods status 

### NewRemote
		* Client sends command id + name (String)
		* Server creates a new remote based on its name and send back response status and remote Id information 

### RecordSignal
		* Client sends command id + remoteID (byte) + remote commandId(byte)
		* Server records the signal , save it and respond with status

### SaveRemoteMetaInf
		* Client sends command id + remoteId (byte) + (int) length of region file bytes + (int) length of the picture + region bytes + pictue bytes
		* Serve responds status  

### LoadRemoteMetaInf
		* Client sends command id + remoteId byte
		* Server responds status + (int) length of region file bytes + (int) length of the picture + region bytes + pictue bytes

		
## Server file structure


    <AppFolder>
        \config.properties (config file contaning key / value pair e.g. username, password, port etc. 
        		This can be located in other place than remotes structure, these being specified relatively to rootpath value from config file )
        \remotes.txt (each line contains one remote - remoteId as long value in string + remote name )
        \remoteId as long value in string folder
            \regions.bin file
            \image.jpg
            \<commandId>.bin - commandId - long value as string
		