#ifndef SERAIL_COM_WIN_H
#define SERAIL_COM_WIN_H

#include <stdio.h>
#include <windows>
#include <iostream>
#include <string>
#include <vcl.h>
#include <vector>


/*   WINAPI Structures
typedef struct _DCB {
DWORD DCBlength; // sizeof(DCB)
DWORD BaudRate; // current baud rate
DWORD fBinary:1; // binary mode, no EOF check
DWORD fParity:1; // enable parity checking
DWORD fOutxCtsFlow:1; // CTS output flow control
DWORD fOutxDsrFlow:1; // DSR output flow control
DWORD fDtrControl:2; // DTR flow control type
DWORD fDsrSensitivity:1; // DSR sensitivity
DWORD fTXContinueOnXoff:1; // XOFF continues Tx
DWORD fOutX:1; // XON/XOFF out flow control
DWORD fInX:1; // XON/XOFF in flow control
DWORD fErrorChar:1; // enable error replacement
DWORD fNull:1; // enable null stripping
DWORD fRtsControl:2; // RTS flow control
DWORD fAbortOnError:1; // abort reads/writes on error
DWORD fDummy2:17; // reserved
WORD wReserved; // not currently used
WORD XonLim; // transmit XON threshold
WORD XoffLim; // transmit XOFF threshold
BYTE ByteSize; // number of bits/byte, 4-8
BYTE Parity; // 0-4=no,odd,even,mark,space
BYTE StopBits; // 0,1,2 = 1, 1.5, 2
char XonChar; // Tx and Rx XON character
char XoffChar; // Tx and Rx XOFF character
char ErrorChar; // error replacement character
char EofChar; // end of input character
char EvtChar; // received event character
WORD wReserved1; // reserved; do not use
} DCB;

typedef struct _COMMTIMEOUTS {
DWORD ReadIntervalTimeout;  // ReadIntervalTimeout � ������������ ���������� � �������������,
                            // ���������� ����� ����� ������������ �� ����� ����������������� ���������.
                            // �� ����� �������� ������ ������ �������� ������������� � ������� ������
                            // ������� �������.
                            // ���� �������� ����� ����� ����������������� ��������� �������� ��������
                            // ��������, �������� ������ ����������� � ��� ������, ����������� � ������,
                            // ���������� � ���������. ������� �������� ������� ���� ��������, ���
                            // ������ ����-��� �� ������������.
DWORD ReadTotalTimeoutMultiplier;  // ReadTotalTimeoutMultiplier � ������ ��������� � �������������,
                                   //  ������������ ��� ���������� ������ ����-���� �������� ������.
                                   // ��� ������ �������� ������ ������ �������� ���������� �� ����������
                                   // ����������� ��� ������ ��������.
DWORD ReadTotalTimeoutConstant;  // ReadTotalTimeoutConstant � ������ ��������� (� �������������),
                                 // ������������ ��� ���������� ������ ����-���� �������� ������.
                                 // ��� ������ �������� ������ ������ �������� ��������� � ����������
                                 // ��������� ReadTotalTimeoutMultiplier �� ���������� ����������� ���
                                 // ������ ��������. ������� �������� ����� ReadTotalTimeoutMultiplier
                                 // � ReadTotalTimeoutConstant ��������, ��� ����� ����-��� ���
                                 // �������� ������ �� ������������.

DWORD WriteTotalTimeoutMultiplier;  //WriteTotalTimeoutMultiplier � ������ ��������� (� �������������),
                                    // ������������ ��� ���������� ������ ����-���� �������� ������.
                                    // ��� ������ �������� ������ ������ �������� ���������� �� ����������
                                    // ������������ ��������.

DWORD WriteTotalTimeoutConstant;   // WriteTotalTimeoutConstant � ������ ��������� (� �������������),
                                   // ������������ ��� ���������� ������ ����-���� �������� ������.
                                   // ��� ������ �������� ������ ������ �������� ������������ � ����������
                                   // ��������� WriteTotalTimeoutMultiplier �� ���������� ������������
                                   // ��������. ������� �������� ����� WriteTotalTimeoutMultiplier �
                                   // WriteTotalTimeoutConstant ��������, ��� ����� ����-��� ��� ��������
                                   // ������ �� ������������.
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

BOOL PurgeComm( HANDLE hFile,
                DWORD dwFlags  // PURGE_TXABORT � ���������� ���������� ��� �������� ������, ���� ���� ��� �� ���������;
                               // PURGE_RXABORT � ���������� ���������� ��� �������� ������, ���� ���� ��� �� ���������;
                               // PURGE_TXCLEAR � ������� ������� �������� � ��������;
                               // PURGE_RXCLEAR � ������� ������� ������ � ��������.
);


typedef struct _COMSTAT
DWORD fCtsHold:1;
DWORD fDsrHold:1;
DWORD fRlsdHold:1;
DWORD fXoffHold:1;
DWORD fXoffSent:1;
DWORD fEof:1;
DWORD fTxim:1;
DWORD fReserved:25;
DWORD cbInQue;        // ����� �������� � �������� ������. ��� ������� ������� �� �����,
                      // �� ��� �� ������� �������� ReadFile;
DWORD cbOutQue;       // ����� �������� � ���������� ������. ��� ������� ��� �� �������� � �����.
} COMSTAT, *LPCOMSTAT;


*/

#define DEF_COMM_DATA_SIZE   8
#define DEF_COMM_PARITY      0  // 0 - no check parity
                                // 1 - odd
                                // 2 - even
                                // 3 - mark
                                // 4 - space

typedef enum
{
 COM_CLEAR,                     // 0
 COM_OK,                        // 1
 COM_INVALID_PARAMETERS,        // 2
 COM_CREATE_ERROR,              // 3
 COM_GETSTATE_ERROR,            // 4
 COM_SETUP_ERROR,               // 5
 COM_SETTIME_ERROR,             // 6
 COM_ERROR_STATE,               // 7
 COM_IO_ERROR,                  // 8
 COM_MASK_PORT_ERROR
}T_Result;


AnsiString GetCOMStatus(AnsiString in_pre, T_Result in_state);

int InitCOM();
HANDLE * GetCommHandle();
int GetCOMCount();
AnsiString GetCOMItem(unsigned int iter);

T_Result OpenCOMPort(unsigned int PortNum,       // number
                     unsigned int BoudRate,      // speed
                     unsigned char DataSize,     // size
                     unsigned char Parity,
                     unsigned char StopBits
                    );

T_Result OpenCOMPort(AnsiString Port,       // name COMx
                     unsigned int BoudRate,      // speed
                     unsigned char DataSize,     // size
                     unsigned char Parity,
                     unsigned char StopBits
                    );
BOOL IsCOMOpen();

T_Result CloseCOMPort();

unsigned int  Set_Boud_Rate(unsigned char index);
unsigned char Set_Data_Size(unsigned char index);
unsigned char Set_Parity(unsigned char index);

T_Result TransmitComPort(void* buffer, DWORD sizeBuffer, DWORD* send);
T_Result ReceiveComPort(void* buffer, DWORD sizeBuffer, DWORD* read);



#endif  // SERAIL_COM_WIN_H
