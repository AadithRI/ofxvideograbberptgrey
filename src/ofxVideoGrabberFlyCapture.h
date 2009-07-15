#ifndef _OFX_VIDEO_GRABBER_FLYCAPTURE
#define _OFX_VIDEO_GRABBER_FLYCAPTURE

#include "ofConstants.h"
#include "ofTexture.h"
#include "ofGraphics.h"
#include "ofTypes.h"
#include "ofUtils.h"

#include "FlyCapture2.h"
using namespace FlyCapture2;



class ofxVideoGrabberPtgrey : public ofBaseVideo {

	public :

		ofxVideoGrabberPtgrey();
		virtual ~ofxVideoGrabberPtgrey();

		void 			listDevices();
		bool 			isFrameNew();
		void			grabFrame();
		void			close();
		bool			initGrabber(int w, int h, bool bTexture=true);
		void			videoSettings();
		unsigned char 	* getPixels();
		ofTexture &		getTextureReference();
		void 			setVerbose(bool bTalkToMe);
		void			setDeviceID(int _deviceID);
		void 			setUseTexture(bool bUse);
		void 			draw(float x, float y, float w, float h);
		void 			draw(float x, float y);
		void			update();

		//the anchor is the point the image is drawn around. 
		//this can be useful if you want to rotate an image around a particular point. 
        void			setAnchorPercent(float xPct, float yPct);	//set the anchor as a percentage of the image width/height ( 0.0-1.0 range )
        void			setAnchorPoint(int x, int y);				//set the anchor point in pixels
        void			resetAnchor();								//resets the anchor to (0, 0)

		float 			getHeight();
		float 			getWidth();

		int			height;
		int			width;
		
		//--------------------------------- flyCapture
		void setBrightness( int value);
		int getBrightness();
		void setExposure( int value);
		int getExposure();
		void setShutter( int value);
		int getShutter();


	
	protected:
                
		bool					bChooseDevice;
		int 					deviceID;
		bool					bUseTexture;
		ofTexture 				tex;
		bool 					bVerbose;
		bool 					bGrabberInited;
	    unsigned char * 		pixels;
		bool 					bIsFrameNew;
        
		//--------------------------------- flyCapture
        Error                   err;
        BusManager		        busMgr;
        PGRGuid                 guid;
	    Camera          		cam;
        CameraInfo              camInfo;
        Format7Info             fmt7Info;
        Format7ImageSettings    fmt7ImageSettings;
        Format7PacketInfo       fmt7PacketInfo;
        Property                frmRate;
	    Image			        rawImage;

        Mode                    k_fmt7Mode;
        PixelFormat             k_fmt7PixFmt;

        Property                prop;
        PropertyInfo            propInfo;

        void PrintError( Error error ){
            printf( "%s\n", error.GetDescription() );
        }

		
        
};




#endif

