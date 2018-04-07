package com.mt.mtxx.image;

/**
 * <pre>
 *     author : Administrator (Jacket)
 *     e-mail : 378315764@qq.com
 *     time   : 2018/01/11
 *     desc   :
 *     version: 1.0
 * </pre>
 */

public class JNI {
    {
        System.loadLibrary("mtimage-jni");  //注意api版本不能高(低于API 23),否则会因和编译so文件的版本对不上而报错 http://blog.csdn.net/qq_17265737/article/details/54139325
    }

    public native void AutoColor(byte[] p1, int p2, int p3, int p4, int p5);


    public native void AutoColorLevel(byte[] p1, int p2, int p3, boolean p4);


    public native void AutoConstrast(byte[] p1, int p2, int p3);


    public native void AutoWhiteBalance(byte[] p1, int p2, int p3);


    public native void BackWeak(byte[] p1, byte[] p2, int p3, int p4, int[] p5, int[] p6, int p7, byte[] p8, int p9, int p10);


    public native void BackWeak2(byte[] p1, int p2, int p3, int p4, int p5, byte[] p6, int p7, int p8);


    public native void BackWeakLine(int[] p1, int[] p2, int p3, int p4, int[] p5, int[] p6, float p7, int p8, int p9);


    public native void BackWeakOne(int[] p1, int[] p2, int p3, int p4, int p5, int p6, byte[] p7, int p8, int p9);


    public native void CColorBalance(boolean p1, int p2, int p3, int p4, int p5, byte[] p6, int p7, int p8);


    public native void ColorModeEx(byte[] p1, byte[] p2);


    public native void CompositeColorEx(byte[] p1, byte[] p2, double p3);


    public native void DrawEx(byte[] p1, byte[] p2);


    public native void ExclusionEx(byte[] p1, byte[] p2, double p3);


    public native void ExclusionEx2(byte[] p1, byte p2, byte p3, byte p4, double p5);


    public native void FaceBeauty(int[] p1, int p2, int p3, int p4);


    public native void FaceBeautyRelease();


    public native void FrameXCBK(int[] p1, int[] p2, int p3, int p4, int p5);


    public native void GaussIIRBlurBrush(int[] p1, int p2, int p3, int p4, int p5);


    public native void GaussIIRBlurImage(byte[] p1, int p2, int p3, int p4, int p5);


    public native double GetDegreeByPoints(int p1, int p2, int p3, int p4);


    public native void Grayscale(byte[] p1, int p2, int p3);


    public native void HardlightEx(byte[] p1, byte[] p2, double p3);


    public native void ImageColorBurnEx(byte[] p1, byte[] p2);


    public native void ImageDarkenEx(byte[] p1, byte[] p2, double p3);


    public native void ImageExclusionEx(byte[] p1, byte[] p2, double p3);


    public native void ImageLightenEx(byte[] p1, byte[] p2, double p3);


    public native void ImageNormalEx(byte[] p1, byte[] p2, double p3);


    public native void ImageOverlayEx(byte[] p1, byte[] p2, double p3);


    public native void ImageScreenEx(byte[] p1, byte[] p2, double p3);


    public native void ImageSoftLightEx(byte[] p1, byte[] p2, double p3);


    public native void LOMO1(int[] p1, int p2, int p3, int[] p4);


    public native void LOMO2(int[] p1, int p2, int p3, int[] p4);


    public native void LightEnEx(byte[] p1, byte[] p2, double p3);


    public native void MakeAllTransparent(byte[] p1, int p2, int p3);


    public native void MultipleEx(byte[] p1, byte[] p2, double p3);


    public native void NoiseEx(byte[] p1, long p2);


    public native void NormalEx(byte[] p1, byte[] p2, double p3);


    public native void OldImage(byte[] p1, int p2, int p3, byte[] p4, int p5, int p6);


    public native void PinLightEx(byte[] p1, byte[] p2);


    public native void PtChangeByRotate(byte[] p1, double p2, double p3, double p4);


    public native void RGBtoXYZ(byte p1, byte p2, byte p3, byte[] p4);


    public native void RGBtoYIQ(byte p1, byte p2, byte p3, byte[] p4);


    public native void RGBtoYUV(byte p1, byte p2, byte p3, byte[] p4);


    public native void Resample(byte[] p1, int p2, int p3, int p4, byte[] p5, int p6, int p7);


    public native void SSkinbeautify(int[] p1, int p2, int p3, int p4, int p5, int p6, double p7);


    public native void ScreenEx(byte[] p1, byte[] p2, double p3);


    public native void SetBackWeakRadius(byte[] p1, int p2, int p3);


    public native void SetColorImage(byte[] p1, int p2, int p3, int p4, int p5, int p6);


    public native void SetGrayScaleEx(byte[] p1);


    public native void Sharp(int[] p1, int p2, int p3, float p4, float p5);


    public native void SharpPreview(int[] p1, int p2, int p3, float p4, float p5);


    public native void SharpPreviewRelease();


    public native void ShiftRGBEx(byte[] p1, byte p2, byte p3, byte p4);


    public native void SkinWhite(int[] p1, int p2, int p3, int p4);


    public native void SoftLightEx(byte[] p1, byte[] p2, double p3);


    public native void StyleBaoColor(int[] p1, int p2, int p3);


    public native void StyleCinnamon(int[] p1, int p2, int p3);


    public native void StyleClassic(int[] p1, int p2, int p3, double p4);


    public native void StyleClassicStudio(int[] p1, int p2, int p3);


    public native void StyleEP1(int[] p1, int[] p2, int p3, int p4);


    public native void StyleEP2(int[] p1, int[] p2, int p3, int p4);


    public native void StyleElegant(int[] p1, int p2, int p3);


    public native void StyleElegantNew(int[] p1, int p2, int p3);


    public native void StyleFP1(int[] p1, int[] p2, int p3, int p4);


    public native void StyleFP2(int[] p1, int[] p2, int p3, int p4);


    public native void StyleFilm(int[] p1, int p2, int p3);


    public native void StyleGP1(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleGP2(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleImpression(int[] p1, int p2, int p3);


    public native void StyleJapanese(int[] p1, int p2, int p3);


    public native void StyleLomoAP1(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleLomoAP2(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleLomoB(int[] p1, int p2, int p3);


    public native void StyleLomoBrightRed(int[] p1, int[] p2, int p3, int p4);


    public native void StyleLomoC(int[] p1, int p2, int p3);


    public native void StyleLomoChristmas(int[] p1, int[] p2, int p3, int p4);


    public native void StyleLomoHDR(int[] p1, int p2, int p3);


    public native void StyleMilk1(int[] p1, int[] p2, int p3, int p4);


    public native void StyleMilk2(int[] p1, int[] p2, int p3, int p4);


    public native void StyleMilk3(int[] p1, int[] p2, int p3, int p4);


    public native void StyleMilk4(int[] p1, int[] p2, int p3, int p4);


    public native void StyleOldPhoto(int[] p1, int[] p2, int p3, int p4);


    public native void StyleOldPhotoP1(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleOldPhotoP2(int[] p1, int[] p2, int p3, int p4, byte[] p5, int p6);


    public native void StyleRetro(int[] p1, int p2, int p3);


    public native void XYZtoRGB(byte p1, byte p2, byte p3, byte[] p4);


    public native void YIQtoRGB(byte p1, byte p2, byte p3, byte[] p4);


    public native void YUVtoRGB(byte p1, byte p2, byte p3, byte[] p4);


    public native int add(int p1, byte p2);


    public native byte[] deal(byte[] p1, int p2, int p3, int p4, int p5, String p6);
}
