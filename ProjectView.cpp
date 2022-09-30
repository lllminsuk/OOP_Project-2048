
// ProjectView.cpp: CProjectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Project.h"
#endif

#include "ProjectDoc.h"
#include "ProjectView.h"

#include<string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProjectView

IMPLEMENT_DYNCREATE(CProjectView, CView)

BEGIN_MESSAGE_MAP(CProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	
	ON_COMMAND(ID_32774, &CProjectView::On32774)
	ON_COMMAND(ID_32775, &CProjectView::On32775)
	ON_UPDATE_COMMAND_UI(ID_32774, &CProjectView::OnUpdate32774)
	ON_UPDATE_COMMAND_UI(ID_32775, &CProjectView::OnUpdate32775)
	ON_COMMAND(ID_32772, &CProjectView::On32772)
	ON_UPDATE_COMMAND_UI(ID_32772, &CProjectView::OnUpdate32772)
END_MESSAGE_MAP()

// CProjectView 생성/소멸
CProjectView::CProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}
CProjectView::~CProjectView()
{
}
BOOL CProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}
// CProjectView 그리기
void CProjectView::OnDraw(CDC* /*pDC*/)
{
	CProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}
// CProjectView 인쇄
BOOL CProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}
void CProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}
void CProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}
// CProjectView 진단
#ifdef _DEBUG
void CProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectDoc* CProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectDoc)));
	return (CProjectDoc*)m_pDocument;
}
#endif //_DEBUG

// CProjectView 메시지 처리기

void CProjectView::OnPaint()
{
	Invalidate();
	MyBoard.ResetCheck(); // reset check

	CPaintDC pdc(this); // device context for painting

	CBrush WHITE0(RGB(255, 255, 255));	//WHITE 0
	CBrush YELLOW2(RGB(255, 255, 0));	//YELLOW 2
	CBrush ORANGE4(RGB(255, 127, 0));	//ORANGE 4
	CBrush GREEN8(RGB(0, 255, 0));		//GREEN 8
	CBrush BLUE16(RGB(0, 0, 255));		//BLUE 16
	CBrush GRAY32(RGB(166, 166, 166)); //GRAY 32
	CBrush PINK64(RGB(255, 0, 255));	//PINK 64
	CBrush CYAN128(RGB(0, 255, 255));	//CYAN 128
	CBrush PURPLE256(RGB(128, 0, 128));	//PURPLE 256
	CBrush VIOLET512(RGB(112, 48, 160)); //VIOLET 512
	CBrush BROWN1024(RGB(207, 110, 54));//BROWN 1024
	CBrush RED2048(RGB(255, 0, 0));	//RED 2048
	int size = 85; // block size = 85
	
	pdc.SetBkMode(TRANSPARENT); // Eliminate the Text Background Color

	////////////////////////////// DRAW COLOR RECTANGLE ///////////////////////////////
	if (OutputMenu == TRUE)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (MyBoard.GetBlock(y, x)->Get_m_number() == 0)			
					pdc.SelectObject(&WHITE0);					// number = 0 , color = WHITE
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 2)		
					pdc.SelectObject(&YELLOW2);					// number = 2 , color = YELLOW
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 4)
					pdc.SelectObject(&ORANGE4);					// number = 4 , color = ORANGE
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 8)
					pdc.SelectObject(&GREEN8);					// number = 8 , color = GREEN
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 16)
					pdc.SelectObject(&BLUE16);					// number = 16 , color = BLUE
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 32)
					pdc.SelectObject(&GRAY32);					// number = 32 , color = GRAY
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 64)
					pdc.SelectObject(&PINK64);					// number = 64 , color = PINK
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 128)
					pdc.SelectObject(&CYAN128);					// number = 128 , color = CYAN
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 256)
					pdc.SelectObject(&PURPLE256);				// number = 256 , color = PURPLE
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 512)
					pdc.SelectObject(&VIOLET512);				// number = 512 , color = VIOLET
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 1024)
					pdc.SelectObject(&BROWN1024);				// number = 1024 , color = BROWN
				else if (MyBoard.GetBlock(y, x)->Get_m_number() == 2048)
					pdc.SelectObject(&RED2048);					// number = 2048 , color = RED
				pdc.Rectangle(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50); // draw rectangle
			}
		}
	}
	//////////////////////////////// DRAW WHITE RECTANGLE /////////////////////////////////
	else if (OutputMenu == FALSE)
	{
		pdc.SelectObject(&WHITE0); // Color = WHITE
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				pdc.Rectangle(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50); // draw rectangle
	}
	//////////////////////////////// PRINT NUMBER ///////////////////////////////
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (MyBoard.GetBlock(y, x)->Get_m_number() == 2)			// print number 2
				pdc.DrawText(_T("2"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 4)		// print number 4
				pdc.DrawText(_T("4"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 8)		// print number 8
				pdc.DrawText(_T("8"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 16)		// print number 16
				pdc.DrawText(_T("16"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 32)		// print number 32
				pdc.DrawText(_T("32"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 64)		// print number 64
				pdc.DrawText(_T("64"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 128)		// print number 128
				pdc.DrawText(_T("128"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 256)		// print number 256
				pdc.DrawText(_T("256"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 512)		// print number 512
				pdc.DrawText(_T("512"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 1024)	// print number 1024
				pdc.DrawText(_T("1024"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			else if (MyBoard.GetBlock(y, x)->Get_m_number() == 2048)	// print number 2048
				pdc.DrawText(_T("2048"), -1, CRect(x * size + 50, y * size + 50, (x + 1) * size + 50, (y + 1) * size + 50), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
	}
	/////////////////////////////////////////// WIN /////////////////////////////////////////////////
	if (MyBoard.CheckEnd())
	{
		if (MessageBox(L"Continue ?", L"WIN!!", MB_YESNO|MB_ICONWARNING) == IDNO) // message box, yes or no
		{ // NO	
			if (LogMenu == TRUE)
				myFile.Close();		// file close
			DestroyWindow();
			exit(0);			// game end
		}
		else
		{ // YES
			if (LogMenu == TRUE)
			{
				myFile.Close();		// file close
				LogMenu = FALSE;
			}
			OutputMenu = TRUE;	// initial setting
			Board newboard;
			MyBoard = newboard; // new board
			OnPaint(); // new game		
		}
	}
	///////////////////////////////////////// LOSE ///////////////////////////////////////////////////
	if (!(MyBoard.CheckUp() || MyBoard.CheckDown() || MyBoard.CheckLeft() || MyBoard.CheckRight()))
	{
		if (MessageBox(L"Do you want new game ?", L"LOSE!!", MB_YESNO|MB_ICONERROR) == IDNO)  // message box, yes or no
		{ // NO	
			if(LogMenu == TRUE)
				myFile.Close();		// file close
			DestroyWindow();
			exit(0);			// game end
		}
		else
		{ // YES
			if (LogMenu == TRUE)
			{
				myFile.Close();		// file close
				LogMenu = FALSE;
			}
			OutputMenu = TRUE;	// initial setting
			Board newboard;
			MyBoard = newboard; // new board
			OnPaint(); // new game		
		}
	}
}

void CProjectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	////////////////////////////////////// KEY_UP //////////////////////////////////////////
	if (nChar == VK_UP)
	{
		if (MyBoard.Up())	// if it do UP COMMAND
		{
			MyBoard.RandomAdd(); // add random 2
			if (LogMenu)	// If the record menu is enabled
			{
				/////////////////////////////// WRITE FILE ///////////////////////////
				string temp = to_string(LogNum);
				myFile.Write(temp.c_str(), UINT(temp.length()));
				myFile.Write(". Key_Up\n[result]\n",18);
				WriteFile();
			}
		}
	}
	////////////////////////////////////// KEY_DOWN //////////////////////////////////////////
	else if (nChar == VK_DOWN)
	{
		if (MyBoard.Down())	// if it do DOWN COMMAND
		{
			MyBoard.RandomAdd();	// add random 2
			if (LogMenu)	// If the record menu is enabled
			{
				/////////////////////////////// WRITE FILE ///////////////////////////
				string temp = to_string(LogNum);
				myFile.Write(temp.c_str(), UINT(temp.length()));
				myFile.Write(". Key_Down\n[result]\n", 20);
				WriteFile();
			}
		}
	}
	////////////////////////////////////// KEY_LEFT //////////////////////////////////////////
	else if (nChar == VK_LEFT)
	{
		if (MyBoard.Left())	// if it do LEFT COMMAND
		{
			MyBoard.RandomAdd();	// add random 2
			if (LogMenu)	// if the record menu is enabled
			{
				/////////////////////////////// WRITE FILE ///////////////////////////
				string temp = to_string(LogNum);
				myFile.Write(temp.c_str(), UINT(temp.length()));
				myFile.Write(". Key_Left\n[result]\n", 20);
				WriteFile();
			}
		}

	}
	////////////////////////////////////// KEY_RIGHT //////////////////////////////////////////
	else if (nChar == VK_RIGHT)
	{
		if (MyBoard.Right())	// if it do RIGHT COMMAND
		{
			MyBoard.RandomAdd();	// add random 2
			if (LogMenu)	// if the record menu is enabled
			{
				/////////////////////////////// WRITE FILE ///////////////////////////
				string temp = to_string(LogNum);
				myFile.Write(temp.c_str(), UINT(temp.length()));
				myFile.Write(". Key_Right\n[result]\n", 21);
				WriteFile();
			}
		}
	}
	OnPaint(); // draw board
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CProjectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	DownButtonX=point.x; // check button down
	CView::OnLButtonDown(nFlags, point);	
}

void CProjectView::OnLButtonUp(UINT nFlags, CPoint point)
{
	UpButtonX = point.x; // check button up
	if (UpButtonX - DownButtonX > 0) // Mouse Left to Right
	{
		int temp;
		//////////////////////////////////// clockwise rotation ///////////////////////////////
		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				temp = MyBoard.GetBlock(y,x)->Get_m_number();
				MyBoard.GetBlock(y, x)->Set_m_number(MyBoard.GetBlock(3 - x, y)->Get_m_number());
				MyBoard.GetBlock(3 - x, y)->Set_m_number(MyBoard.GetBlock(3 - y, 3 - x)->Get_m_number());
				MyBoard.GetBlock(3 - y, 3 - x)->Set_m_number(MyBoard.GetBlock(x, 3 - y)->Get_m_number());
				MyBoard.GetBlock(x, 3 - y)->Set_m_number(temp);
			}
		}
		if (LogMenu)	// if the record menu is enabled
		{
			/////////////////////////////// WRITE FILE ///////////////////////////
			string temp = to_string(LogNum);
			myFile.Write(temp.c_str(), UINT(temp.length()));
			myFile.Write(". Mouse_Left_to_Right\n[result]\n", 31);
			WriteFile();
		}
	}
	else if (UpButtonX - DownButtonX < 0)	// Mouse Right to Left
	{
		int temp;
		//////////////////////////////////// counterclockwise rotation ///////////////////////////////
		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				temp = MyBoard.GetBlock(y, x)->Get_m_number();
				MyBoard.GetBlock(y, x)->Set_m_number(MyBoard.GetBlock(x, 3 - y)->Get_m_number());
				MyBoard.GetBlock(x, 3 - y)->Set_m_number(MyBoard.GetBlock(3 - y, 3 - x)->Get_m_number());
				MyBoard.GetBlock(3 - y, 3 - x)->Set_m_number(MyBoard.GetBlock(3 - x, y)->Get_m_number());
				MyBoard.GetBlock(3 - x, y)->Set_m_number(temp);
			}
		}
		if (LogMenu)	// if the record menu is enabled
		{
			/////////////////////////////// WRITE FILE ///////////////////////////
			string temp = to_string(LogNum);
			myFile.Write(temp.c_str(), UINT(temp.length()));
			myFile.Write(". Mouse_Right_to_Left\n[result]\n", 31);
			WriteFile();
		}
	}	
	OnPaint();	// draw board
	CView::OnLButtonUp(nFlags, point);
}

void CProjectView::On32774() // menu colors and numbers
{
	OutputMenu = TRUE;
	OnPaint(); // draw board
}

void CProjectView::On32775() // menu only numbers
{
	OutputMenu = FALSE;
	OnPaint(); // draw
}

void CProjectView::OnUpdate32774(CCmdUI* pCmdUI)
{
	if (OutputMenu == TRUE)		// Current memu is menu colors and numbers
		pCmdUI->SetCheck(TRUE);		// Check
	else
		pCmdUI->SetCheck(FALSE);	// Uncheck
}

void CProjectView::OnUpdate32775(CCmdUI* pCmdUI)
{
	if (OutputMenu == FALSE)	// Current memu is menu only numbers
		pCmdUI->SetCheck(TRUE);		// Check
	else
		pCmdUI->SetCheck(FALSE);	// Uncheck
}

void CProjectView::On32772() // record menu
{
	if (LogMenu == FALSE)
	{
		LogMenu = TRUE;
		myFile.Open(_T("log.txt"), CFile::modeCreate | CFile::modeWrite); // File Opne
	}
}
void CProjectView::OnUpdate32772(CCmdUI* pCmdUI)
{
	if (LogMenu == TRUE)	// Current memu is record menu
		pCmdUI->SetCheck(TRUE);		// Check
	else
		pCmdUI->SetCheck(FALSE);	// Uncheck
}

//////////////////////////////////// WRITE BOARD to FILE ///////////////////////////////////////
void CProjectView::WriteFile()
{
	string temp;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (MyBoard.GetBlock(y, x)->Get_m_number() == 0)
			{
				myFile.Write("     ", 5);
				continue;
			}
			temp = to_string(MyBoard.GetBlock(y, x)->Get_m_number());
			myFile.Write(temp.c_str(), UINT(temp.length()));
			if (temp.length() == 1)
				myFile.Write("    ", 4);
			else if (temp.length() == 2)
				myFile.Write("   ", 3);
			else if (temp.length() == 3)
				myFile.Write("  ", 2);
			else if (temp.length() == 4)
				myFile.Write(" ", 1);
		}
		myFile.Write("\n", UINT(1));
	}
	myFile.Write("\n", 1);
	LogNum++;
}
