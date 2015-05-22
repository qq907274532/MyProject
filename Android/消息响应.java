package com.example.bec_004;

import java.io.File;
import java.io.IOException;

import android.os.Bundle;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

@SuppressLint("ShowToast")
public class MainActivity extends Activity 
{
	private Button BtnView;		// ���������ť����
	private Button BtnRead;		// ������ȡ��ť����
	private Button BtnWrite;	// ����д�밴ť����

    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
    	// ���Ҷ�ӦView ID
        BtnView = (Button)findViewById(R.id.BtnView);
        BtnRead = (Button)findViewById(R.id.BtnRead);
        BtnWrite = (Button)findViewById(R.id.BtnWrite);
        
		BtnView.setOnClickListener(ListenView);
		BtnRead.setOnClickListener(ListenRead);
		BtnWrite.setOnClickListener(ListenWrite);

    }

	@Override
    public boolean onCreateOptionsMenu(Menu menu) 
    {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
	
	// �����ť��Ϣ��Ӧ
	OnClickListener ListenView = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "�����ť�����");
		}
	};
	
	// ��ȡ�ļ���ť��Ϣ��Ӧ
	OnClickListener ListenRead = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "��ȡ��ť�����");

			File file = new File("/mnt/sdcard/text");
			Log.i("xiaokang", "�ļ����󱻴���"); 

			if(!file.exists())
			{
				try 
				{
					file.createNewFile();		// �����ļ�
					Log.i("xiaokang", "�ļ������ɹ�");
				} 
				catch (IOException e) 
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			else
			{
				Toast.makeText(MainActivity.this, "�ļ��Ѿ�����", 1000);
				Log.i("xiaokang", "�ļ�����ʧ��");
			}
			
			file.canWrite();
		}
	};
	
	// д�밴ť��Ϣ��Ӧ
	OnClickListener ListenWrite = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "д�밴ť�����");
			//file.delete();	// ɾ���ļ�
		}
	};
}