#ifndef __YBMODALDIALOG_H__
#define __YBMODALDIALOG_H__
#include "frame/YBCtrlBase.h"
#include "frame/YBCtrlEnvCfg.h"
YBCTRL_NAMESPACE_BEGIN
//
class YBCtrlImageStatic;
//
class YBCTRL_API YBModalDialog : public YBCtrlBase {
public:
	YBModalDialog( bool bAutoExit = false, unsigned int uExitTimeMS = 2000 );
	virtual ~YBModalDialog();
	
	// interface
protected:
	virtual void _createUI( HWND hWndModalDlg, HINSTANCE hInst ) = 0;
	virtual unsigned int _getWndHeight() const = 0;
	virtual unsigned int _getWndWidth() const = 0;
	virtual void _drawSelf( HDC hDC ){};

public:
	YBCTRL_WNDMSGMAP_DECLARE()
		
public:
	int doModal( HWND hWndParent );
	void setBKImageId( unsigned int uImageId, 
		unsigned int uLFixed, unsigned int uTFixed, unsigned int uRFixed, unsigned int uBFixed );

protected:
	void endModal( int nCode );

protected:
	void _onWM_PAINT( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_ERASEBKGND( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_LBUTTONDOWN( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_SYSCOMMAND( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_DESTROY( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_TIMER( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	
protected:
	void _drawStatus( HDC hDC );
	void _drawBK( HDC hDC );
private:
	void _runModalLoop();
	void _disableParentWnd( HWND hWndParent );
	void _enableParentWnd( HWND hWndParent );
	void _resetStatus();
	YBCtrlImageStatic* _getImageStatic( unsigned int uImageId );
	HWND _getTopWnd( HWND hWndParent );
    bool _isIdleMessage( unsigned int uMessage );
    bool _pumpMessage();

private:
	unsigned int m_uFlag;
	int m_nRetCode;
	unsigned int m_uImageIdBK;
	unsigned int m_uLFixed;
	unsigned int m_uTFixed;
	unsigned int m_uRFixed;
	unsigned int m_uBFixed;
	unsigned int m_uExitElapse;
    POINT m_ptCursorLast;
    unsigned int m_uMessageLast;
};


YBCTRL_NAMESPACE_END
#endif //__YBMODALDIALOG_H__