
// seed2.0Dlg.h: 头文件
//

#pragma once

enum DrawingMode {
	PointMode,
	LineMode,
	EllipseMode,
	RectangleMode,
	OwnerDrawingMode,
	FillMode

};

// Cseed20Dlg 对话框
class Cseed20Dlg : public CDialogEx
{
// 构造
public:
	Cseed20Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEED20_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	COLORREF LineColor;
	COLORREF ShapeColor;    //颜色


	
	bool isfilled;   // 0 无填充 
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	
	int LineWidth;//线宽
	afx_msg void OnEnChangeEdit1();
	CComboBox m_fill;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	CPoint DownPoint;  //鼠标左键按下
	CPoint UpPoint;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	int Mode;

	void DrawLine();
	void DrawEllipse();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_Mode;

	void AdvancedSeedFill();

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	bool startdrawing;

	CPoint lastpoint;
};
