#define MAX_VERTEX_NUM 20                   //ͼ�ж����������
#define InfoType int                        //�ߺ��е���Ϣ�����������
#define VertexType int                      //ͼ�������������
typedef enum {unvisited,visited}VisitIf;    //�߱�־��
typedef struct EBox{
    VisitIf mark;                           //��־��
    int ivex,jvex;                          //�����߶����������е�λ���±�
    struct EBox * ilink,*jlink;             //�ֱ�ָ����ivex��jvex��ص���һ����
    InfoType *info;                         //�߰�������������Ϣ���ָ��
}EBox;
typedef struct VexBox{
    VertexType data;                        //����������
    EBox * firstedge;                       //������صĵ�һ���ߵ�ָ����
}VexBox;
typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];//�洢ͼ�ж��������
    int vexnum,degenum;//��¼;�ж�������ͱ߸����ı���
}AMLGraph;
