
// seed2.0Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "seed2.0.h"
#include "seed2.0Dlg.h"
#include "afxdialogex.h"
#include "LinkStack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cseed20Dlg 对话框



Cseed20Dlg::Cseed20Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEED20_DIALOG, pParent)
	, LineWidth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cseed20Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, LineWidth);
	DDV_MinMaxInt(pDX, LineWidth, 0, 30);
	DDX_Control(pDX, IDC_COMBO1, m_fill);
	DDX_Control(pDX, IDC_COMBO2, m_Mode);
}

BEGIN_MESSAGE_MAP(Cseed20Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cseed20Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cseed20Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &Cseed20Dlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cseed20Dlg::OnCbnSelchangeCombo1)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cseed20Dlg::OnCbnSelchangeCombo2)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// Cseed20Dlg 消息处理程序

BOOL Cseed20Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	LineColor = RGB(0, 0, 0);
	ShapeColor = RGB(255, 0, 0);

	
	LineWidth = 5;

	m_fill.AddString(TEXT("有填充"));
	m_fill.AddString(TEXT("无填充"));
	m_fill.SetCurSel(1);

	m_Mode.AddString(TEXT("点"));
	m_Mode.AddString(TEXT("线"));
	m_Mode.AddString(TEXT("椭圆"));
	m_Mode.AddString(TEXT("自由"));
	m_Mode.AddString(TEXT("填充模式"));

	m_Mode.SetCurSel(0);


	UpdateData(FALSE);

	Mode = PointMode;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cseed20Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cseed20Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{                                 //绘制点（绘图）

	//	CPaintDC dc(this); // 用于绘制的设备上下文

		//dc.SetPixel(x + i, y, RGB(0, 255, 0));
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cseed20Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cseed20Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CColorDialog colorDlg(LineColor);         // 构造颜色对话框，传入初始颜色值
	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”
	{
		LineColor = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值
		
	}


}





void Cseed20Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CColorDialog colorDlg(ShapeColor);         // 构造颜色对话框，传入初始颜色值
	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”
	{
		ShapeColor = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值

	}
}


void Cseed20Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void Cseed20Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_fill.GetCurSel();

	if (index == 0) isfilled = true;
	else isfilled = false;


}


void Cseed20Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	    DownPoint = point;   //记录鼠标按下点（种子点）

		if (Mode == PointMode) {


			CClientDC dc(this); // 用于绘制的设备上下文

			dc.SetPixel(point.x, point.y, LineColor);

		}
		else if (Mode == OwnerDrawingMode) {
			startdrawing = true;
			lastpoint = point;
		}

		
	CDialogEx::OnLButtonDown(nFlags, point);
}


void Cseed20Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	UpPoint = point;

	switch (Mode) {

	case LineMode:
		DrawLine();
		break;
	case EllipseMode:
		DrawEllipse();
		break;
	case FillMode:
		AdvancedSeedFill();
		break;
	case OwnerDrawingMode:
		startdrawing = false;
		break;
	default:
		;
	}
	

	
	CDialogEx::OnLButtonUp(nFlags, point);
}

void Cseed20Dlg::DrawLine()

{
	CClientDC dc(this);

	CPen pen(0, LineWidth, LineColor);
	CPen* pPen = dc.SelectObject(&pen);

	

	dc.MoveTo(DownPoint.x, DownPoint.y);   //起点左键按下处
	dc.LineTo(UpPoint.x,  UpPoint.y);   //终点鼠标松开处
	dc.SelectObject(pPen);
}

void Cseed20Dlg::DrawEllipse()
{
	CClientDC dc(this);

	CPen oPen(0, LineWidth, LineColor);
	CPen* pPen = dc.SelectObject(&oPen);
	CBrush fillBrush(ShapeColor);
	CBrush transBrush;
	transBrush.CreateStockObject(NULL_BRUSH);

	CBrush* pBrush;
	if (isfilled) {

		pBrush = dc.SelectObject(&fillBrush);  //启用非透明画刷
	}
	else {


		pBrush = dc.SelectObject(&transBrush);
	}



	dc.Ellipse(DownPoint.x, DownPoint.y, UpPoint.x, UpPoint.y);
	dc.SelectObject(pPen);
	dc.SelectObject(pBrush);

}


void Cseed20Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_Mode.GetCurSel();

	if (index == 0) Mode = PointMode;
	else if (index == 1) Mode = LineMode;
	else if (index == 2) Mode = EllipseMode;
	else if (index == 3) Mode = OwnerDrawingMode;
	else if (index == 4) Mode = FillMode;
	else Mode = LineMode;
	
//	UpdateData(TRUE);


}

void Cseed20Dlg::AdvancedSeedFill()
{
	LinkStack<CPoint> stack;
	CPoint Temp_Point;
	// 将种子点入栈
	stack.Push(UpPoint);
	

	CPoint leftPoint;
	

	CPoint rightPoint;
	

	CPoint upPoint;
	

	CPoint downPoint;
	

	CClientDC dc(this);

	CRect rectDlg;

	GetClientRect(rectDlg);//获得窗体的大小
	int width = rectDlg.Width();
	int height = rectDlg.Height();

	COLORREF color = dc.GetPixel(Temp_Point);

	while (!stack.IsEmpty())
	{
		// 出栈一个点

		stack.Pop(Temp_Point);

		if (Temp_Point.x >= 0 && Temp_Point.x < width && Temp_Point.y >= 0 && Temp_Point.y < height)
		{
			color = dc.GetPixel(Temp_Point);  // 获取指定点的颜色值
			if (color != ShapeColor&&color != LineColor)
			{
				// 填充当前点
				dc.SetPixel(Temp_Point.x, Temp_Point.y, ShapeColor);
				//dc.SetPixel(point.x, point.y, ShapeColor);

				leftPoint = Temp_Point;
				rightPoint = Temp_Point;
				upPoint = Temp_Point;
				downPoint = Temp_Point;

				leftPoint.Offset(-1, 0);
				rightPoint.Offset(1, 0);
				upPoint.Offset(0, -1);
				downPoint.Offset(0, 1);

				if (rightPoint.x >= 0 && rightPoint.x < width && rightPoint.y >= 0 && rightPoint.y < height && dc.GetPixel(rightPoint) != ShapeColor && dc.GetPixel(rightPoint) != LineColor)
				{
					stack.Push(rightPoint);
				}
				if (leftPoint.x >= 0 && leftPoint.x < width && leftPoint.y >= 0 && leftPoint.y < height && dc.GetPixel(leftPoint) != ShapeColor && dc.GetPixel(leftPoint) != LineColor)
				{
					stack.Push(leftPoint);
				}
				if (downPoint.x >= 0 && downPoint.x < width && downPoint.y >= 0 && downPoint.y < height && dc.GetPixel(downPoint) != ShapeColor && dc.GetPixel(downPoint) != LineColor)
				{
					stack.Push(downPoint);
				}
				if (upPoint.x >= 0 && upPoint.x < width && upPoint.y >= 0 && upPoint.y < height && dc.GetPixel(upPoint) != ShapeColor && dc.GetPixel(upPoint) != LineColor)
				{
					stack.Push(upPoint);
				}

			}

		}
	}
}


void Cseed20Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//point 当前时刻点
	if (Mode == OwnerDrawingMode&& startdrawing) {



		CClientDC dc(this);

		CPen pen(0, LineWidth, LineColor);
		CPen* pPen = dc.SelectObject(&pen);



		dc.MoveTo(lastpoint.x, lastpoint.y);   //起点左键按下处
		dc.LineTo(point.x, point.y);   //终点鼠标松开处
		dc.SelectObject(pPen);

		lastpoint = point;

		
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
