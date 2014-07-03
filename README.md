urtoy
=====


Notes:
-----

 - Command IDs, remoteIds and remote commandIds  - are one byte value
 - int  values are sent as 32 bits big endien values
 - server status value - one byte value 
 - String representation - 32 bits int length value + UTF-8 bytes

Commands:
-----


#### Login 
		* Client - Sends command id
		* Server - Server Sends Nonce (String value no more than 20 chars  )
		* Client - Response (username + ':' +string( (int) charCount(password+nonce))  - This might be replaced with md5 in he future 
		* Server - Response status ok or close connection (one bytes)

#### Logout
		* Client sends command id
		* Server close connection

#### LoadRemoteMetaInf
		* Client sends command id + remoteId (8 bytes long value)
		* Server responds status + (int) length of region file bytes + (int) length of the picture + region bytes + pictue bytes

#### GetRemotes
		* Client sends command id
		* Server sends back status + List of pairs (byte - remoteId , String remoteName )

#### SendCommand
		* Client sends command id + remoteId (byte) + remote commandID (byte)
		* Server respods status 

#### NewRemote
		* Client sends command id + remoteId(byte) + name (String)
		* Server creates a new remote and its name and responds status 

#### SaveRemoteMetaInf
		* Client sends command id + (int) length of region file bytes + (int) length of the picture + region bytes + pictue bytes
		* Serve responds status  

#### RecordSignal
		* Client sends command id + remoteID (byte) + remote commandId(byte)
		* Server records the signal , save it and respond with status

		
# Server file structure


    <AppFolder>
        \remotes.txt (each line contains one remote - remoteId as long value in string + remote name )
        \remoteId as long value in string folder
            \regions.bin file
            \image.jpg
            \<commandId>.bin - commandId - long value as string
		