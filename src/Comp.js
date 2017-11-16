import React, { Component } from 'react';
import ComponentContainer from './component/ComponentContainer.js'
import {List, ListItem} from 'material-ui';
import MenuContainer from './MenuContainer';

export default class extends Component {
  constructor() {
    super();
    this.state = {
      ListObject: {
        '統計分析': [
          '數據視圖',
          '協方差',
          '經驗概率密度圖',
          '全表統計',
          '卡方擬合性檢驗',
          '卡方獨立性檢驗',
          '箱線圖',
          '散點圖',
          '相關係數矩陣'
        ],
        '機器學習': {
          '二分類': ['GBDT二分類', 'PS-SMART二分訓練', '線性支持向量機', '邏輯回歸二分類'],
          '多分類': [],
          '聚類': [],
          '回歸': [],
        }
      }
    };
  }
  render() {
    return (
      <MenuContainer>

        <List>
          
        </List>
      </MenuContainer>
    )
  }
}
