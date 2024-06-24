param (
    [string]$number
)

if (-not $number) {
    Write-Host "Usage: .\deploy_cherry.ps1 <number>"
    exit 1
}

# 读取cherry.yaml文件内容
$content = Get-Content -Path "cherry.yaml" -Raw

# 替换占位符
$content = $content -replace '\{%1\}', $number

# 将替换后的内容写入临时文件
$tempFile = New-TemporaryFile
Set-Content -Path $tempFile -Value $content

# 执行kubectl apply命令
kubectl apply -f $tempFile

# 删除临时文件
Remove-Item -Path $tempFile
