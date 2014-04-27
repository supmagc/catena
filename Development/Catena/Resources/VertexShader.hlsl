struct VSOUT {
    float4 vPos: POSITION;
    float4 vCol : COLOR;
};

row_major float4x4 mWVP : register(c0);

VSOUT main(float4 vPos: POSITION, float4 vCol: COLOR)
{
    VSOUT oOut;
    float4 vTmp = mul(mWVP, vPos);
    oOut.vPos = vPos; //mul(mWVP, vPos);
    oOut.vCol = vTmp * vCol;
    return oOut;
}